#pragma once
#include"Node.h"
#include"Node.cpp"
template<typename T>
class linkedlist
{
	Node<T>*head;
	Node<T>*tail;
	int size;
public:
	linkedlist();
	void appand(T val);
	int length();
	bool find(T val);
	T at(int pos);
	void insert_At(T val, int pos);
	void delete_at(int pos);
	void clear();
	~linkedlist();
};