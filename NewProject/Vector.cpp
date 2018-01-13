#pragma once
#include "Vector.h"

template<typename T>
void Vector<T>::push_back(T val)
{
	vec.appand(val);
}
template<typename T>
void Vector<T>::pop_back()
{
	vec.remove_at(vec.length - 1);
}
template<typename T>
int Vector<T>::size()
{
	return vec.length();
}
template<typename T>
bool Vector<T>::empty()
{
	return (bool)(!vec.length());
}
template<typename T>
T Vector<T>::at(int pos)
{
	return vec.at(pos);
}

template<typename T>
Vector<T>::~Vector()
{
	vec.~Arraylist();
}
