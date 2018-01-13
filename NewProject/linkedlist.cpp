#pragma once
#include"linkedlist.h"
#include<assert.h>
template<typename T>
linkedlist<T>::linkedlist()
{
	head = tail = NULL;
	size = 0;
}
template<typename T>
void linkedlist<T>::appand(T val)
{
	Node<T>*NewNode = new Node<T>(val);
	if (head == NULL)
	{
		head = NewNode;
		tail = NewNode;
	}
	else
	{
		tail->next = NewNode;
		tail = tail->next;
	}
	size++;
}
template<typename T>
int linkedlist<T>::length()
{
	return size;
}
template<typename T>
bool linkedlist<T>::find(T val)
{
	Node<T>*tmp = head;
	for (int i = 0; i < size; i++)
	{
		if (tmp->value == val)
			return true;
		tmp = tmp->next;
	}
	return false;
}
template<typename T>
T linkedlist<T>::at(int pos)
{
	assert(pos >= 0 && pos < size);
	Node<T>*tmp = head;
	for (int i = 0; i < pos; i++)
		tmp = tmp->next;
	return tmp->value;
}
template<typename T>
void linkedlist<T>::insert_At(T val, int pos)
{
	assert(pos >= 0 && pos < size);
	Node<T>*tmp = head;
	Node<T>*NewNode = new Node<T>(val);
	if (pos == 0)
	{
		NewNode->next = head;
		head = NewNode;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			tmp = tmp->next;
		NewNode->next = tmp->next;
		tmp->next = NewNode;

	}
	size++;
}
template<typename T>
void linkedlist<T>::delete_at(int pos)
{
	assert(pos >= 0 && pos < size);
	Node<T>* tmp = head;
	if (pos == 0)
	{
		head = head->next;
		delete tmp;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			tmp = tmp->next;
		Node<T>* del = tmp->next;
		tmp->next = del->next;
		delete del;
		if (pos == size - 1)
			tail = tmp;
	}
	size--;
}

template <typename T>
void linkedlist<T>::clear()
{
	if (size == 0)
		return;
	Node<T>* tmp = head->next;
	while (tmp->next != 0)
	{
		delete head;
		head = tmp;
		tmp = tmp->next;
	}

	delete head;
	head = tail = 0;
	size = 0;
}
template<typename T>
linkedlist<T>::~linkedlist()
{
	clear();
}