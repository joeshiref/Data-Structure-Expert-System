#pragma once
#include"linkedlist.h"
#include"linkedlist.cpp"
template<typename T>
class Queue
{
	linkedlist<T>Q;
public:
	void push(T);
	void pop();
	bool empty();
	T front();
	int size();
	~Queue();
};

