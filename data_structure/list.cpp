#include "list.h"

///////////////////////////////////////////////////////////
// list
///////////////////////////////////////////////////////////
template<typename T>
inline list<T>::list()
	: head_(nullptr), tail_(nullptr), size_(0)
{}

template<typename T>
inline list<T>::list(size_t size, T value)
	: head_(nullptr), tail_(nullptr), size_(0)
{
	// set head
	head_ = new node<T>();
	node* move = head_;

	for (size_t i = 0; i < size_; ++i)
	{
		node* new_node = new node<T>(); // assign new node
		move->next = new_node; // connect nect
		new_node->prev = move; // connect prev
		move = new_node; // move to the next
	}

	// set tail
	tail_ = move;
}

template<typename T>
list<T>::~list()
{
	clear();
}

template<typename T>
size_t list<T>::size() const
{
	return size_;
}

template<typename T>
bool list<T>::empty() const
{
	return size_ == 0;
}

template<typename T>
void list<T>::clear()
{
	while (head_)
	{
		node* next = head_->next; // temp next
		delete head_; // delete head
		head_ = next; // set new head(saved next)
	}

	size_ = 0; // set size 0
}

template<typename T>
const T& list<T>::at(int index) const
{
	if (unsigned(index) >= size_)
		throw std::out_of_range("out of range!\n");

	node* res = head_;
	while (index--)
		res = res->next;

	return res;
}

template<typename T>
void list<T>::push_back(const T& obj)
{
	// empty case
	if (!head_)
	{
		tail_ = head_ = new node<T>;
		return;
	}

	// assign new node
	node* new_node = new node<T>;

	// connect both nodes
	tail_->next = new_node;
	new_node->prev = tail_;

	// set new tail
	tail_ = new_node;

	++size_;
}

template<typename T>
void list<T>::pop_back()
{
	node* to_delete = tail_; // save tail to delete
	tail_ = tail_->prev; // move tail to the prev
	tail_->next = nullptr; // set tail's next to nullptr
	delete to_delete; // delete the node

	--size_;
}

template<typename T>
void list<T>::erase(const_iterator it)
{
	node* prev (it)->prev;
	--size_;
}

template<typename T>
void list<T>::insert(const_iterator it, const T& obj)
{
	++size_;
}

template<typename T>
void list<T>::merge(list<T>& other)
{
	// double check the other's head is valid
	if (other->head_)
	{
		tail_->next = other->head_;
		other->head_->prev = tail_;

		tail_ = other->tail_;
		other->
	}

	size_ += other->size_;
}

template<typename T>
typename list<T>::const_iterator list<T>::begin(void) const
{
	return const_iterator(head_);
}

template<typename T>
typename list<T>::const_iterator list<T>::end(void) const
{
	return const_iterator(head_ + size_);
}

template<typename T>
typename list<T>::const_reverse_iterator list<T>::rbegin(void) const
{
	return const_reverse_iterator(head_ + size_ - 1);
}

template<typename T>
typename list<T>::const_reverse_iterator list<T>::rend(void) const
{
	return const_reverse_iterator(dummyHead_);
}

///////////////////////////////////////////////////////////
// const_iterator
///////////////////////////////////////////////////////////
template<typename T>
inline list<T>::const_iterator::const_iterator(typename list<T>::node<T>* p)
{
	current = p;
}

template<typename T>
inline typename list<T>::const_iterator list<T>::const_iterator::operator++(void)
{
	current = current->next;
	return const_iterator(current);
}

template<typename T>
inline typename list<T>::const_iterator list<T>::const_iterator::operator--(void)
{
	current = current->prev;
	return const_iterator(current);
}

template<typename T>
inline const T& list<T>::const_iterator::operator*(void) const
{
	return *(current->value);
}

template<typename T>
inline bool list<T>::const_iterator::operator!=(const const_iterator& rhs) const
{
	return rhs.current != current;
}

///////////////////////////////////////////////////////////
// const_iterator
///////////////////////////////////////////////////////////
template<typename T>
inline list<T>::const_reverse_iterator::const_reverse_iterator(T* p)
{
	current = p;
}

template<typename T>
inline typename list<T>::const_reverse_iterator list<T>::const_reverse_iterator::operator++(void)
{
	current = current->prev;
	return const_reverse_iterator(current);
}

template<typename T>
inline typename list<T>::const_reverse_iterator list<T>::const_reverse_iterator::operator--(void)
{
	current = current->next;
	return const_reverse_iterator(current);
}

template<typename T>
inline const T& list<T>::const_reverse_iterator::operator*(void) const
{
	return *(current->value);
}

template<typename T>
inline bool list<T>::const_reverse_iterator::operator!=(const const_reverse_iterator& rhs) const
{
	return rhs.current != current;
}
