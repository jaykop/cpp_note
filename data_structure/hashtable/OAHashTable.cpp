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
}

template<typename T>
inline OAHashTable<T>::~OAHashTable()
{
	clear();
}

template<typename T>
void OAHashTable<T>::insert(const char* Key, const T& Data) throw(OAHashTableException)
{
	if (!Slots_)
		throw OAHashTableException(OAHashTableException::E_NO_MEMORY, "E_NO_MEMORY");

	++Stats_.Count_;

	unsigned probing = 1;

	double currentLoadFactor = Stats_.Count_ / double(Stats_.TableSize_);
	if (currentLoadFactor >= MaxLoadFactor_)
		GrowTable();

	unsigned newIndex = Stats_.PrimaryHashFunc_(Key, Stats_.TableSize_);
	unsigned add = 1;
	if (Stats_.SecondaryHashFunc_)
		add += Stats_.SecondaryHashFunc_(Key, Stats_.TableSize_ - 1);

	// find the unoccupied slot
	while (Slots_[newIndex].State == OAHTSlot::OAHTSlot_State::OCCUPIED)
	{
		if (!strcmp(Slots_[newIndex].Key, Key))
			throw OAHashTableException(OAHashTableException::E_DUPLICATE, "E_DUPLICATE");

		++probing;
		newIndex += add;
		newIndex = newIndex % Stats_.TableSize_;
	}

	// update probing
	Stats_.Probes_ += probing;

	// update the data
	unsigned strSize = strlen(Key);
	strncpy(Slots_[newIndex].Key, Key, strSize + 1);
	Slots_[newIndex].Data = Data;
	Slots_[newIndex].State = OAHTSlot::OAHTSlot_State::OCCUPIED;
}

template<typename T>
void OAHashTable<T>::remove(const char* Key) throw(OAHashTableException)
{
	OAHTSlot* found = nullptr;
	int index = IndexOf(Key, found);
	if (index < 0)
		throw OAHashTableException(OAHashTableException::E_ITEM_NOT_FOUND, "Key not in table");

	// decrease the count
	--Stats_.Count_;

	// MARK
	if (DeletionPolicy_ == OAHTDeletionPolicy::MARK)
		found->State = OAHTSlot::OAHTSlot_State::DELETED;

	// PACK
	else
	{
		std::queue<OAHTSlot*> cluster;
		found->State = OAHTSlot::OAHTSlot_State::UNOCCUPIED;

		unsigned removeIndex = unsigned(index);
		unsigned next = (removeIndex + 1) % Stats_.TableSize_;

		while (Slots_[next].State == OAHTSlot::OAHTSlot_State::OCCUPIED)
		{
			Slots_[next].State = OAHTSlot::OAHTSlot_State::UNOCCUPIED;
			cluster.push(&Slots_[next]);
			next = (++next) % Stats_.TableSize_;
			--Stats_.Count_;
		}

		while (!cluster.empty())
		{
			auto slot = cluster.front();
			cluster.pop();
			insert(slot->Key, slot->Data);
		}
	}
}

template<typename T>
const T& OAHashTable<T>::find(const char* Key) const throw(OAHashTableException)
{
	OAHTSlot* found = nullptr;
	int index = IndexOf(Key, found);
	
	if (index < 0) 
		throw OAHashTableException(OAHashTableException::E_ITEM_NOT_FOUND, "Item not found in table");

	return found->Data;
}

template<typename T>
void OAHashTable<T>::clear(void)
{
	for (unsigned i = 0; i < Stats_.TableSize_; ++i)
		Slots_[i].State = OAHTSlot::UNOCCUPIED;

	Stats_.Count_ = 0;
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
		if (Slots_[i].State == OAHTSlot::OAHTSlot_State::OCCUPIED)
		{
			unsigned probing = 1;
			unsigned newIndex = Stats_.PrimaryHashFunc_(Slots_[i].Key, newSize);

			unsigned add = 1;
			if (Stats_.SecondaryHashFunc_)
				add += Stats_.SecondaryHashFunc_(Slots_[i].Key, Stats_.TableSize_ - 1);

			while (tmpSlot[newIndex].State == OAHTSlot::OAHTSlot_State::OCCUPIED)
			{
				++probing;
				newIndex += add;
				newIndex = newIndex % newSize;
			}

			tmpSlot[newIndex] = Slots_[i];

			Stats_.Probes_ += probing;
		}
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
	unsigned probing = 1;

	unsigned add = 1;
	if (Stats_.SecondaryHashFunc_)
		add += Stats_.SecondaryHashFunc_(Key, Stats_.TableSize_ - 1);

	while (strcmp(Slots_[findIndex].Key, Key) // identical key 
		&& probing <= Stats_.TableSize_) // at least one cycle
	{
		++probing;
		findIndex += add;
		findIndex = findIndex % Stats_.TableSize_;
	}

	// set slot
	Slot = &Slots_[findIndex];

	// update probing count
	Stats_.Probes_ += probing;

	if (!strcmp(Slots_[findIndex].Key, Key))
		return int(findIndex);

	return -1;
}
