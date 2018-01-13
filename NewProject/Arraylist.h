#pragma once
template<typename T>
class Arraylist
{
	int size;
	int elements;
	T*arr;

public:
	Arraylist();
	Arraylist(int);
	void appand(T);
	bool find(T);
	int length();
	void remove_at(int);
	void insert_at(int,T);
	T at(int pos);
	void clear();
	void expand();
	~Arraylist();
};

