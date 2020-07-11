#include "OAHashTable.h"
#include <cmath>
#include <queue>

template<typename T>
inline OAHashTable<T>::OAHashTable(const OAHTConfig& Config)
	: MaxLoadFactor_(Config.MaxLoadFactor_),
	GrowthFactor_(Config.GrowthFactor_),
	DeletionPolicy_(Config.DeletionPolicy_),
	FreeProc_(Config.FreeProc_)
{
	Stats_.TableSize_ = Config.InitialTableSize_;
	Stats_.PrimaryHashFunc_ = Config.PrimaryHashFunc_;
	Stats_.SecondaryHashFunc_ = Config.SecondaryHashFunc_;

	InitTable();
	//Slots_ = new OAHTSlot[Stats_.TableSize_];
}

template<typename T>
inline OAHashTable<T>::~OAHashTable()
{
	clear();
}

template<typename T>
void OAHashTable<T>::insert(const char* Key, const T& Data) throw(OAHashTableException)
{
	++Stats_.Count_;

	double currentLoadFactor = Stats_.Count_ / double(Stats_.TableSize_);

	if (currentLoadFactor >= MaxLoadFactor_)
		GrowTable();

	unsigned probing = 1;
	unsigned newIndex = Stats_.PrimaryHashFunc_(Key, Stats_.TableSize_);

	// find the unoccupied slot
	while (Slots_[newIndex].State == OAHTSlot::OAHTSlot_State::OCCUPIED)
	{
		++probing;
		++newIndex;
		newIndex = newIndex % Stats_.TableSize_;
	}

	// update probing
	Stats_.Probes_ += probing;

	// update the data
	unsigned strSize = strlen(Key);
	strncpy(Slots_[newIndex].Key, Key, strSize);
	Slots_[newIndex].Key[strSize] = '\0';
	Slots_[newIndex].Data = Data;
	Slots_[newIndex].State = OAHTSlot::OAHTSlot_State::OCCUPIED;

}

template<typename T>
void OAHashTable<T>::remove(const char* Key) throw(OAHashTableException)
{
	unsigned probing = 1;
	unsigned removeIndex = Stats_.PrimaryHashFunc_(Key, Stats_.TableSize_);

	while (strcmp(Slots_[removeIndex].Key, Key) && probing <= Stats_.TableSize_)
	{
		++probing;
		++removeIndex;
		removeIndex = removeIndex % Stats_.TableSize_;
	}

	// found the item
	if (!strcmp(Slots_[removeIndex].Key, Key) &&
		Slots_[removeIndex].State == OAHTSlot::OAHTSlot_State::OCCUPIED)
	{
		// decrease the count
		--Stats_.Count_;

		// MARK
		if (DeletionPolicy_ == OAHTDeletionPolicy::MARK)
		{
			Slots_[removeIndex].State = OAHTSlot::OAHTSlot_State::DELETED;
		}

		// PACK
		else
		{
			std::queue<OAHTSlot*> cluster;
			Slots_[removeIndex].State = OAHTSlot::OAHTSlot_State::UNOCCUPIED;
			unsigned next = (removeIndex + 1) % Stats_.TableSize_;
			while (Slots_[next].State == OAHTSlot::OAHTSlot_State::OCCUPIED)
			{
				Slots_[next].State = OAHTSlot::OAHTSlot_State::UNOCCUPIED;
				cluster.push(&Slots_[next]);
				++next;
				next = next % Stats_.TableSize_;
				--Stats_.Count_;
			}

			while (!cluster.empty())
			{
				auto slot = cluster.front();
				cluster.pop();
				insert(slot->Key, slot->Data);
			}
		}

		// update probing
		Stats_.Probes_ += probing;
	}

	else 
		throw OAHashTableException::E_ITEM_NOT_FOUND;
}

template<typename T>
const T& OAHashTable<T>::find(const char* Key) const throw(OAHashTableException)
{
	unsigned findIndex = Stats_.PrimaryHashFunc_(Key, Stats_.TableSize_);

	// find the slot
	bool found = false;
	for (unsigned i = 0; i < Stats_.TableSize_; ++i)
	{
		int index = (i + findIndex) % Stats_.TableSize_;
		if (Slots_[index].Key == Key)
		{
			findIndex = index;
			found = true;
			break;
		}
	}

	// not found
	if (!found) throw OAHashTableException::E_ITEM_NOT_FOUND;

	return Slots_[findIndex].Data;
}

template<typename T>
void OAHashTable<T>::clear(void)
{
	MaxLoadFactor_ = GrowthFactor_ = 0.0;
	FreeProc_ = nullptr;
	Stats_ = OAHTStats();

	delete[] Slots_;
	Slots_ = nullptr;
}

template<typename T>
OAHTStats OAHashTable<T>::GetStats(void) const
{
	return Stats_;
}

template<typename T>
const typename OAHashTable<T>::OAHTSlot* OAHashTable<T>::GetTable(void) const
{
	return Slots_;
}

template<typename T>
void OAHashTable<T>::InitTable(void)
{
	Slots_ = new OAHTSlot[Stats_.TableSize_];
}

template<typename T>
void OAHashTable<T>::GrowTable(void) throw(OAHashTableException)
{
	// increase the expansion number
	++Stats_.Expansions_;

	// get new container
	double factor = std::ceil(Stats_.TableSize_ * GrowthFactor_);
	unsigned newSize = GetClosestPrime(static_cast<unsigned>(factor));
	OAHTSlot* tmpSlot = new OAHTSlot[newSize];

	// move existing data to the new slots
	for (unsigned i = 0; i < Stats_.TableSize_; ++i)
	{
		unsigned probing = 0;
		unsigned newIndex = Stats_.PrimaryHashFunc_(Slots_[i].Key, newSize);

		if (Slots_[i].State == OAHTSlot::OAHTSlot_State::OCCUPIED)
			++probing;

		while (tmpSlot[newIndex].State == OAHTSlot::OAHTSlot_State::OCCUPIED)
		{
			++probing;
			++newIndex;
			newIndex = newIndex % newSize;
		}

		Stats_.Probes_ += probing;
		tmpSlot[newIndex] = Slots_[i];
	}

	// set new container
	delete[] Slots_;
	Slots_ = tmpSlot;

	Stats_.TableSize_ = newSize;
}

template<typename T>
int OAHashTable<T>::IndexOf(const char* Key, OAHTSlot*& Slot) const
{
	unsigned findIndex = Stats_.PrimaryHashFunc_(Key, Stats_.TableSize_);

	// find the slot
	bool found = false;
	for (unsigned i = 0; i < Stats_.TableSize_; ++i)
	{
		int index = (i + findIndex) % Stats_.TableSize_;
		if (Slots_[index].Key == Key)
		{
			findIndex = index;
			found = true;
			break;
		}
	}

	// not found
	if (!found) return -1;
	return findIndex;
}
