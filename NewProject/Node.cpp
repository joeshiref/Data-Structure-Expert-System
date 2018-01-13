#pragma once
#include"Node.h"

template<typename T>
Node<T>::Node()
{
	next = NULL;
	value = 0;
}
template<typename T>
Node<T>::Node(T val)
{
	next = NULL;
	value = val;
}