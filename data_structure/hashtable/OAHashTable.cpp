#include "OAHashTable.h"

template<typename T>
inline OAHashTable<T>::OAHashTable(const OAHTConfig& Config)
{
}

template<typename T>
inline OAHashTable<T>::~OAHashTable()
{
}

template<typename T>
void OAHashTable<T>::insert(const char* Key, const T& Data) throw(OAHashTableException)
{
}

template<typename T>
void OAHashTable<T>::remove(const char* Key) throw(OAHashTableException)
{
}

template<typename T>
const T& OAHashTable<T>::find(const char* Key) const throw(OAHashTableException)
{
	return 0;
}

template<typename T>
void OAHashTable<T>::clear(void)
{
}

template<typename T>
OAHTStats OAHashTable<T>::GetStats(void) const
{
	return OAHTStats();
}

template<typename T>
const typename OAHashTable<T>::OAHTSlot* OAHashTable<T>::GetTable(void) const
{
	return nullptr;
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
