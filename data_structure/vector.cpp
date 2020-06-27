#include "vector.h"

///////////////////////////////////////////////////////////
// vector
///////////////////////////////////////////////////////////
template<typename T>
inline vector<T>::vector()
	: dummyHead_((T*)malloc(sizeof(T) * 2)),
	head_(dummyHead_ + 1), size_(0), capacity_(0)
{}

template<typename T>
inline vector<T>::vector(size_t size, T value)
	: head_((T*)malloc(sizeof(T)* size + 2)),
	head_(dummyHead_ + 1), size_(size), capacity_(size)
{
	for (size_t i = 0; i < size_; ++i)
		*(head_ + i) = value;
}

template<typename T>
vector<T>::~vector()
{
	clear();
	free(dummyHead_);
}

template<typename T>
void vector<T>::reserve(size_t newCapacity)
{
	if (newCapacity <= capacity_)
		return;

	capacity_ = newCapacity;

	// assign new vector
	T* dummyTemp = (T*)malloc(sizeof(T) * (capacity_ + 2));
	T* headTemp = dummyTemp + 1;
	for (size_t i = 0; i < size_; ++i)
		*(headTemp + i) = *(head_ + i);
	
	// update the head
	free(dummyHead_);
	dummyHead_ = dummyTemp;
	head_ = headTemp;
}

template<typename T>
void vector<T>::resize(size_t newSize, T value)
{	
	if (size_ > newSize)
	{
		size_ = newSize;
		return;
	}

	else if (newSize > capacity_)
		capacity_ = newSize;

	// assign new vector
	T* dummyTemp = (T*)malloc(sizeof(T) * (capacity_ + 2));
	T* headTemp = dummyTemp + 1;
	for (size_t i = 0; i < size_; ++i)
		*(headTemp + i) = *(head_ + i);
	for (size_t i = size_; i < newSize; ++i)
		*(headTemp + i) = value;

	size_ = newSize;

	// update the head
	free(dummyHead_);
	dummyHead_ = dummyTemp;
	head_ = headTemp;
}

template<typename T>
size_t vector<T>::size() const
{
	return size_;
}

template<typename T>
size_t vector<T>::capacity() const
{
	return capacity_;
}

template<typename T>
bool vector<T>::empty() const
{
	return size_ == 0;
}

template<typename T>
void vector<T>::clear()
{
	size_ = 0;
}

template<typename T>
const T& vector<T>::at(int index) const
{
	if (unsigned(index) >= size_)
		throw std::out_of_range("out of range!\n");

	return *(head_ + index);
}

template<typename T>
T& vector<T>::operator[](int index)
{
	if (unsigned(index) >= size_)
		throw std::out_of_range("out of range!\n");

	return *(head_ + index);
}

template<typename T>
void vector<T>::push_back(const T& obj)
{
	if (size_ == capacity_)
	{
		float floatCapacity = 1.5f * float(capacity_);
		size_t newCapacity = size_t(floatCapacity);
		if (newCapacity == capacity_) ++newCapacity;
		reserve(newCapacity);
	}
	++size_;
	*(head_ + size_ - 1) = obj;
}

template<typename T>
void vector<T>::pop_back()
{
	size_ = size_ > 0 ? --size_ : 0;
}

template<typename T>
typename vector<T>::const_iterator vector<T>::begin(void) const
{
	return const_iterator(head_);
}

template<typename T>
typename vector<T>::const_iterator vector<T>::end(void) const
{
	return const_iterator(head_ + size_);
}

template<typename T>
typename vector<T>::const_reverse_iterator vector<T>::rbegin(void) const
{
	return const_reverse_iterator(head_ + size_ - 1);
}

template<typename T>
typename vector<T>::const_reverse_iterator vector<T>::rend(void) const
{
	return const_reverse_iterator(dummyHead_);
}

///////////////////////////////////////////////////////////
// const_iterator
///////////////////////////////////////////////////////////
template<typename T>
inline vector<T>::const_iterator::const_iterator(T* p)
{
	current = p;
}

template<typename T>
inline typename vector<T>::const_iterator vector<T>::const_iterator::operator++(void)
{
	++current;
	return const_iterator(current);
}

template<typename T>
inline typename vector<T>::const_iterator vector<T>::const_iterator::operator--(void)
{
	--current;
	return const_iterator(current);
}

template<typename T>
inline const T& vector<T>::const_iterator::operator*(void) const
{
	return *current;
}

template<typename T>
inline bool vector<T>::const_iterator::operator!=(const const_iterator& rhs) const
{
	return rhs.current != current;
}

///////////////////////////////////////////////////////////
// const_iterator
///////////////////////////////////////////////////////////
template<typename T>
inline vector<T>::const_reverse_iterator::const_reverse_iterator(T* p)
{
	current = p;
}

template<typename T>
inline typename vector<T>::const_reverse_iterator vector<T>::const_reverse_iterator::operator++(void)
{
	--current;
	return const_reverse_iterator(current);
}

template<typename T>
inline typename vector<T>::const_reverse_iterator vector<T>::const_reverse_iterator::operator--(void)
{
	++current;
	return const_reverse_iterator(current);
}

template<typename T>
inline const T& vector<T>::const_reverse_iterator::operator*(void) const
{
	return *current;
}

template<typename T>
inline bool vector<T>::const_reverse_iterator::operator!=(const const_reverse_iterator& rhs) const
{
	return rhs.current != current;
}
