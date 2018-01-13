#pragma once
#include"Stack.h"

template<typename T>
void Stack<T>::pop()
{
	V.delete_at(V.length() - 1);
}
template<typename T>
void Stack<T>::push(T Val)
{
	V.appand(Val);
}
template<typename T>
T Stack<T>::top()
{
	return  V.at(V.length() - 1);
}

template<typename T>
bool Stack<T>::empty()
{
	return (bool)(!V.length());
}
template<typename T>
Stack<T>::~Stack()
{
	V.~linkedlist();
}
