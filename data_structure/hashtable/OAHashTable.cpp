#include "OAHashTable.h"
#include <cmath>

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
		unsigned new_size = GetClosestPrime(static_cast<unsigned>(factor));
		OAHTSlot* temp = new OAHTSlot[new_size];

		// copy existing container to the new one
		for (unsigned i = 0; i < Stats_.TableSize_; ++i)
			temp[i] = Slots_[i];

		// set new container
		delete[] Slots_;
		Stats_.TableSize_ = new_size;
		Slots_ = temp;
	}

	// get the index to add
	unsigned indexToUpdate = Stats_.PrimaryHashFunc_(Key, Stats_.TableSize_);

	// find the unoccupied slot
	unsigned probing = 0; 
	for (unsigned i = 0; i < Stats_.TableSize_; ++i)
	{
		++probing;
		int index = (i + indexToUpdate) % Stats_.TableSize_;
		if (Slots_[index].State != OAHTSlot::OAHTSlot_State::OCCUPIED)
		{
			indexToUpdate = index;
			break;
		}
	}

	// update probing
	Stats_.Probes_ += probing;

	// update the data
	unsigned strSize = strnlen(Key, MAX_KEYLEN);
	strncpy(Slots_[indexToUpdate].Key, Key, strSize);
	Slots_[indexToUpdate].Key[strSize] = '\0';
	Slots_[indexToUpdate].Data = Data;
	Slots_[indexToUpdate].State = OAHTSlot::OAHTSlot_State::OCCUPIED;
}

template<typename T>
void OAHashTable<T>::remove(const char* Key) throw(OAHashTableException)
{
	--Stats_.Count_;
}

template<typename T>
const T& OAHashTable<T>::find(const char* Key) const throw(OAHashTableException)
{
	unsigned indexToReturn = Stats_.PrimaryHashFunc_(Key, Stats_.TableSize_);

	// find the slot
	bool found = false;
	for (unsigned i = 0; i < Stats_.TableSize_; ++i)
	{
		int index = (i + indexToReturn) % Stats_.TableSize_;
		if (Slots_[index].Key == Key)
		{
			indexToReturn = index;
			found = true;
			break;
		}
	}

	// not found
	if (!found) return 0;

	return Slots_[indexToReturn].Data;
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
