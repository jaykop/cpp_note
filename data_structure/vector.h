#pragma once
#include <iterator>

template<typename T>
struct vector {

	vector();
	vector(size_t size);
	vector(size_t size, T value);
	~vector();

	size_t size() const;
	size_t capacity() const;
	bool empty() const;
	void clear();

	const T& at(int index) const;
	T& operator[](int index);

	void push_back();
	void pop_back();
	const T& back() const { return *head_; }
	const T& front() const { *(head_ + size_); }

	//**************************************************
	// const_iterator
	class const_iterator
	{
	public:
		const_iterator(T* p); // conversion ctor

		const_iterator& operator++(void); // pre-increment
		const_iterator& operator--(void); // pre-decrement                          
		const T& operator*(void) const; // dereference op

		// inequality op
		bool  operator!=(const const_iterator& rhs) const;

	private:
		T* current; //!< Pointer to the current node
	};
	//**************************************************

	  // iteration
	const_iterator begin(void) const;  // the first node
	const_iterator end(void) const;    // one past the end

	const_iterator rbegin(void) const; // the last node
	const_iterator rend(void) const;   // one before the first

private:

	size_t size_;
	T* head_ = nullptr;

};


#include "vector.cpp"
