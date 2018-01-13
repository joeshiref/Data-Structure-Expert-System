#include "Arraylist.h"
#include <assert.h>

#pragma once

template<typename T>
Arraylist<T>::Arraylist()
{
	elements = 0;
	size = 100;
	arr = new T[size];
}
template<typename T>
Arraylist<T>::Arraylist(int sz)
{
	elements = 0;
	size = sz;
	arr = new T[size];
}
template<typename T>
void Arraylist<T>::appand(T val)
{
	if (elements == size)
		expand();
	arr[elements] = val;
	elements++;
}
template<typename T>
bool Arraylist<T>::find(T val)
{
	for (int i = 0; i < elements; i++)
	{
		if (arr[i] == val)
			return true;
	}
	return false;
}
template<typename T>
int Arraylist<T>::length()
{
	return elements;
}
template<typename T>
void Arraylist<T>::remove_at(int pos)
{
	assert(pos<elements);
	for (int i = pos; i < elements - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	elements--;
}
template<typename T>
void Arraylist<T>::insert_at(int pos, T val)
{
	assert(pos<elements);
	if (elements == size)
		expand();
	for (int i = elements; i>pos; i--)
		arr[i] = arr[i - 1];
	arr[pos] = val;
	elements++;
}
template <typename T>
T Arraylist<T>::at(int pos)
{
	assert(pos<elements);
	return arr[pos];
}

template <typename T>
void Arraylist<T>::clear()
{
	delete[] arr;
	size = 5;
	arr = new T[size];
	elements = 0;
}
template <typename T>
void Arraylist<T>::expand()
{
	size *= 2;
	T *arr_2 = new T[size];
	for (int i = 0; i < elements; i++)
	{
		arr_2[i] = arr[i];
	}
	delete[]arr;
	arr = arr_2;
}

template<typename T>
Arraylist<T>::~Arraylist()
{
	clear();
}
