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

	Slots_ = new OAHTSlot[Stats_.TableSize_];
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

	//	When an insertion will cause the maximum load factor to be surpassed, you must grow the
	//	table before inserting. A load factor of 1.0 means that you will grow the table only when an
	//	item is to be inserted into a full table.
	if (currentLoadFactor >= MaxLoadFactor_)
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
				newIndex = ++newIndex % newSize;
			}

			Stats_.Probes_ += probing;
			tmpSlot[newIndex] = Slots_[i];
		}

		// set new container
		delete[] Slots_;
		Slots_ = tmpSlot;

		Stats_.TableSize_ = newSize;
	}

	unsigned probing = 1;
	unsigned newIndex = Stats_.PrimaryHashFunc_(Key, Stats_.TableSize_);

	// find the unoccupied slot
	while (Slots_[newIndex].State == OAHTSlot::OAHTSlot_State::OCCUPIED)
	{
		++probing;
		newIndex = ++newIndex % Stats_.TableSize_;
	}

	// update probing
	Stats_.Probes_ += probing;

	// update the data
	unsigned strSize = strnlen(Key, MAX_KEYLEN);
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
		removeIndex = ++removeIndex % Stats_.TableSize_;
		++probing;
	}

	if (!strcmp(Slots_[removeIndex].Key, Key) &&
		Slots_[removeIndex].State == OAHTSlot::OAHTSlot_State::OCCUPIED)
	{
		Slots_[removeIndex].State = OAHTSlot::OAHTSlot_State::DELETED;

		// MARK
		if (DeletionPolicy_ == OAHTDeletionPolicy::MARK)
			;

		// PACK
		else
		{
			// std::queue<OAHTSlot*> cluster;
			unsigned move = removeIndex;
			unsigned next = (move + 1) % Stats_.TableSize_;

			while (Slots_[next].State == OAHTSlot::OAHTSlot_State::OCCUPIED)
			{
				Slots_[next].State = OAHTSlot::OAHTSlot_State::UNOCCUPIED;
				insert(Slots_[next].Key, Slots_[next].Data);
				// cluster.push(&Slots_[next]);
				move = next;
				next = ++next % Stats_.TableSize_;
				++probing;
			}

			/*while (!cluster.empty())
			{
				auto slot = cluster.front();
				cluster.pop();
				insert(slot->Key, slot->Data);
			}*/
		}

		--Stats_.Count_;
	}

	// update probing
	Stats_.Probes_ += probing;
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
	if (!found) return 0;

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
}

template<typename T>
void OAHashTable<T>::GrowTable(void) throw(OAHashTableException)
{
}

template<typename T>
int OAHashTable<T>::IndexOf(const char* Key, OAHTSlot*& Slot) const
{
	return 0;
}
