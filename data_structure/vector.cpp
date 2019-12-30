#include "vector.h"

///////////////////////////////////////////////////////////
// vector
///////////////////////////////////////////////////////////
template<typename T>
inline vector<T>::vector()
	: head_(NULL), size_(0)
{
}

template<typename T>
inline vector<T>::vector(size_t size)
	: head_(NULL), size_(size)
{

	head_ = (T*)malloc(sizeof(T) * size);
	for (int i = 0; i < size_; i++) {
		*(head_ + i) = 0;
	}
}

template<typename T>
inline vector<T>::vector(size_t size, T value)
	: head_(NULL), size_(size)
{
	head_ = (T*)malloc(sizeof(T) * size);
	for (int i = 0; i < size_; i++) {
		*(head_ + i) = value;
	}
}

template<typename T>
vector<T>::~vector()
{
	clear();
}

template<typename T>
size_t vector<T>::size() const
{
	return size_;
}

template<typename T>
bool vector<T>::empty() const
{
	return size_ == 0;
}

template<typename T>
void vector<T>::clear()
{
	free(head_);
	head_ = NULL;
	size_ = 0;
}

template<typename T>
const T& vector<T>::at(int index) const
{
	return *(head_ + index);
}

template<typename T>
T& vector<T>::operator[](int index)
{
	return *(head_ + index);
}

template<typename T>
vector<T>::const_iterator vector<T>::begin(void) const
{
	return const_iterator(head_);
}

template<typename T>
vector<T>::const_iterator vector<T>::end(void) const
{
	return const_iterator(head_ + size_)); // need dummy
}

template<typename T>
vector<T>::const_iterator vector<T>::rbegin(void) const
{
	return const_iterator(head_ + size_ - 1);
}

template<typename T>
vector<T>::const_iterator vector<T>::rend(void) const
{
	return const_iterator(head_ - 1); // need dummy
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
inline vector<T>::const_iterator& vector<T>::const_iterator::operator++(void)
{
	return const_iterator(current + 1);
}

template<typename T>
inline vector<T>::const_iterator& vector<T>::const_iterator::operator--(void)
{
	return const_iterator(current - 1);
}

template<typename T>
inline const T& vector<T>::const_iterator::operator*(void) const
{
	return *current;
}

template<typename T>
inline bool vector<T>::const_iterator::operator!=(const const_iterator& rhs) const
{
	return rhs.cucrrent != current;
}
