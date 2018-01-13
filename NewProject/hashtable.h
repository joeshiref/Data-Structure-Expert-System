#pragma once
#include <iostream>
#include<vector>
#include <stdio.h>
#include<string.h>
#include <string>

using namespace std;

template <typename K, typename Q>
class hashtable
{
	struct MyStruct
	{
		K key;
		Q value;
	};
	int elements, stop;
	MyStruct *arr;
	int sz;
	vector<int>v;
	int *visited;
	int *deletion;
	void little_sieve();
	unsigned int hashing(K);
	int prob_hashing(K, int);
	void set_values();
	//long long fast_pow(int a, int b);
	void expand();
	int next_prime();
public:
	hashtable();
	bool isEmpty();
	void remove(K);
	void put(K, Q);
	Q get(K key);
	~hashtable();
};

