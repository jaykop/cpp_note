#pragma once

template<typename T>
class list {

	template<typename T>
	struct node
	{
		node* prev = nullptr;
		node* next = nullptr;
		T value = 0;
	};

public:

	list();
	list(size_t size, T value = 0);
	~list();

	size_t size() const;
	bool empty() const;
	void clear();

	const T& at(int index) const;

	//**************************************************
	// const_iterator
	class const_iterator
	{
	public:
		const_iterator(node<T>* n); // conversion ctor

		const_iterator operator++(void); // pre-increment
		const_iterator operator--(void); // pre-decrement                          
		const T& operator*(void) const; // dereference op

		// inequality op
		bool  operator!=(const const_iterator& rhs) const;

	private:
		node<T>* current; //!< Pointer to the current node
	};

	// const_reverse_iterator
	class const_reverse_iterator
	{
	public:
		const_reverse_iterator(T* p); // conversion ctor

		const_reverse_iterator operator++(void); // pre-increment
		const_reverse_iterator operator--(void); // pre-decrement                          
		const T& operator*(void) const; // dereference op

		// inequality op
		bool  operator!=(const const_reverse_iterator& rhs) const;

	private:
		node* current; //!< Pointer to the current node
	};
	//**************************************************

	// iteration
	const_iterator begin(void) const;  // the first node
	const_iterator end(void) const;    // one past the end

	const_reverse_iterator rbegin(void) const; // the last node
	const_reverse_iterator rend(void) const;   // one before the first

	void insert(const_iterator it, const T& obj);
	void erase(const_iterator it);
	void push_back(const T& obj);
	void pop_back();
	const T& back() const { return tail_->value; }
	const T& front() const { return head_->value; }
	void merge(list& other);

private:

	size_t size_;
	node* head_ = nullptr, *tail_ = nullptr;

};

#include "list.cpp"
