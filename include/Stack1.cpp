#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

template <typename T>
class Stack
{
private:
	T * array_;
	size_t array_size_;
	size_t count_;

public:
	Stack();
	size_t count() const;
	void push(T const &);
	T pop();
	T last() const;
	void print();

};


template <typename T>
Stack<T>::Stack() {
	array_ = nullptr;
	array_size_ = 0;
	count_ = 0;
}

template <typename T>
size_t Stack<T>::count() const {
	return count_;

}

template <typename T>
void Stack<T>::push(T const& value) {

	if (array_size_ == 0)
	{
		array_size_ = 1;
		array_ = new T[array_size_]();
	}
	else if (array_size_ == count_)
	{
		array_size_ *= 2;
		T * array_new = new T[array_size_]();
		for (unsigned int i = 0; i < count_; ++i)
			array_new[i] = array_[i];
		delete[] array_;
		array_ = array_new;
	}
	array_[count_++] = value;
}

template <typename T>
T Stack<T>::pop() {

	if (count_ == 0)
	{
		throw "Stack is empty!";
	}
	T result = array_[count_--];
	return result;
}

template <typename T>
T Stack<T>::last()const
{
	if (count_ == 0)
		throw logic_error("Stack is empty");
	else return array_[count_ - 1];
}

template <typename T>
void Stack<T>::print()
{
	for (unsigned int i = 0; i < count_; ++i)
		cout << array_[i] << " ";
	cout << endl;
}
