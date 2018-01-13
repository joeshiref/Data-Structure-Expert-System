#pragma once
#include"linkedlist.h"
#include"linkedlist.cpp"

template<typename T>

class Stack
{
	linkedlist<T>V;
public:
	void push(T Val);
	void pop();
	T top();
	bool empty();
	~Stack();
};