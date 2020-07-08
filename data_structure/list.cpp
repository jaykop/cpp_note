#include "list.h"

///////////////////////////////////////////////////////////
// list
///////////////////////////////////////////////////////////
template<typename T>
inline list<T>::list()
	: head_(nullptr), tail_(nullptr), 
	dummyHead_(new node), dummyTail_(new node), size_(0)
{
	// set dummies
	dummyHead_->next = dummyTail_;
	dummyTail_->prev = dummyHead_;
}

template<typename T>
inline list<T>::list(size_t size, T value)
	: head_(nullptr), tail_(nullptr),
	dummyHead_(new node), dummyTail_(new node), size_(0)
{
	// set head
	head_ = new node;
	node* move = head_;

	for (size_t i = 0; i < size_; ++i)
	{
		node* new_node = new node; // assign new node
		move->next = new_node; // connect nect
		new_node->prev = move; // connect prev
		move = new_node; // move to the next
	}

	// set tail
	tail_ = move;

	// set dummies
	dummyHead_->next = head_;
	head_->prev = dummyHead_;

	dummyTail_->prev = tail_;
	tail_->next = dummyTail_;
}

template<typename T>
list<T>::~list()
{
	clear();

	delete dummyHead_;
	delete dummyTail_;
	dummyHead_ = nullptr;
	dummyTail_ = nullptr;
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
	while (head_ != dummyTail_)
	{
		node* next = head_->next; // temp next
		delete head_; // delete head
		head_ = next; // set new head(saved next)
	}

	head_ = tail_ = nullptr;

	size_ = 0; // set size 0

	// set dummies
	dummyHead_->next = dummyTail_;
	dummyTail_->prev = dummyHead_;
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
	// increase size
	++size_;

	// empty case
	if (!head_)
	{
		tail_ = head_ = new node;
		head_->value = obj;

		// set dummies
		dummyHead_->next = head_;
		head_->prev = dummyHead_;

		dummyTail_->prev = tail_;
		tail_->next = dummyTail_;

		return;
	}

	// assign new node
	node* new_node = new node;
	new_node->value = obj;

	// connect both nodes
	tail_->next = new_node;
	new_node->prev = tail_;

	// set new tail
	tail_ = new_node;

	// set dummy tail
	dummyTail_->prev = tail_;
	tail_->next = dummyTail_;
}

template<typename T>
void list<T>::pop_back()
{
	node* to_delete = tail_; // save tail to delete
	tail_ = tail_->prev; // move tail to the prev
	tail_->next = dummyTail_; // set tail's next to dummy tail
	dummyTail_->prev = tail_; // set dummy tail's prev to tail
	delete to_delete; // delete the node

	--size_;

	if (size_ == 1)
		head_ = tail_;

	else if (!size_)
	{
		// set dummies
		dummyHead_->next = dummyTail_;
		dummyTail_->prev = dummyHead_;
	}
}

template<typename T>
void list<T>::erase(const_iterator it)
{
	node* prev = it.current->prev, *next = it.current->next;

	prev->next = next;
	next->prev = prev;

	if (it.current == head_)
	{
		delete head_;
		head_ = next;
	}

	--size_;

	if (size_ == 1)
		head_ = tail_;

	if (!size_)
	{
		// set dummies
		dummyHead_->next = dummyTail_;
		dummyTail_->prev = dummyHead_;
	}
}

template<typename T>
void list<T>::insert(const_iterator it, const T& obj)
{
	++size_;

	node* prev = it.current->prev;
	node* new_node = new node;
	new_node->value = obj;

	prev->next = new_node;
	new_node->prev = prev;
	it.current->prev = new_node;
	new_node->next = it.current;

	if (it.current == head_)
		head_ = new_node;
}

template<typename T>
void list<T>::merge(list<T>& other)
{
	// double check the other's head is valid
	if (other.head_)
	{
		tail_->next = other.head_;
		other.head_->prev = tail_;

		tail_ = other.tail_;
		tail_->next = dummyTail_;
		dummyTail_->prev = tail_;

		size_ += other.size_;

		// set other
		// set other's dummies
		other.tail_ = other.head_ = nullptr;
		other.dummyHead_->next = other.dummyTail_;
		other.dummyTail_->prev = other.dummyHead_;
		other.size_ = 0;
	}
}

template<typename T>
typename list<T>::const_iterator list<T>::begin(void) const
{
	return const_iterator(head_);
}

template<typename T>
typename list<T>::const_iterator list<T>::end(void) const
{
	return const_iterator(dummyTail_);
}

template<typename T>
typename list<T>::const_reverse_iterator list<T>::rbegin(void) const
{
	return const_reverse_iterator(tail_);
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
inline list<T>::const_iterator::const_iterator(typename list<T>::node* p)
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
inline typename list<T>::const_iterator list<T>::const_iterator::operator+(int i)
{
	node* move = current;
	while (i--) move = move->next;
	return const_iterator(move);
}

template<typename T>
inline typename list<T>::const_iterator list<T>::const_iterator::operator-(int i)
{
	node* move = current;
	while (i--) move = move->prev;
	return const_iterator(move);
}

template<typename T>
inline const T& list<T>::const_iterator::operator*(void) const
{
	return current->value;
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
inline list<T>::const_reverse_iterator::const_reverse_iterator(typename list<T>::node* p)
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
inline typename list<T>::const_reverse_iterator list<T>::const_reverse_iterator::operator+(int i)
{
	node* move = current;
	while (i--) move = move->prev;
	return const_reverse_iterator(move);
}

template<typename T>
inline typename list<T>::const_reverse_iterator list<T>::const_reverse_iterator::operator-(int i)
{
	node* move = current;
	while (i--) move = move->next;
	return const_reverse_iterator(move);
}

template<typename T>
inline const T& list<T>::const_reverse_iterator::operator*(void) const
{
	return current->value;
}

template<typename T>
inline bool list<T>::const_reverse_iterator::operator!=(const const_reverse_iterator& rhs) const
{
	return rhs.current != current;
}
