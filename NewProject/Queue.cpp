#pragma once
#include "Queue.h"


template<typename T>
void Queue<T>::push(T val)
{
	Q.appand(val);
}
template<typename T>
void Queue<T>::pop()
{
	Q.delete_at(0);
}
template<typename T>
T Queue<T>::front()
{
	return Q.at(0);
}
template<typename T>
bool Queue<T>::empty()
{
	return (bool)(!Q.length());
}
template<typename T>
int Queue<T>::size()
{
	return Q.length();
}
template<typename T>
Queue<T>::~Queue()
{
	Q.~linkedlist();
}
