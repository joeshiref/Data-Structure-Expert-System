#pragma once
#include"Arraylist.h"
#include"Arraylist.cpp"
template<typename T>
class Vector
{
	Arraylist<T>vec;
public:
	void push_back(T);
	void pop_back();
	bool empty();
	int size();
	T at(int);
	~Vector();
};

