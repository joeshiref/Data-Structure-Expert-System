#pragma once
#include "hashtable.h"
#include <iostream>
#include<vector>
#include <stdio.h>
#include <assert.h>
#include <string>
#include <stdlib.h>
#include <ctype.h>
#include <typeinfo>
#include <sstream> 

using namespace std;

template <typename K, typename Q>
hashtable<K, Q>::hashtable()
{
	elements = 0;
	stop = 5;
	little_sieve();
	sz = v[stop];
	arr = new MyStruct[sz];
	visited = new int[sz];
	deletion = new int[sz];
	set_values();
}
template <typename K, typename Q>
void hashtable<K, Q>::remove(K key)
{
	int indx = hashing(key), j = 0;
	if (arr[indx].key == key)
		deletion[indx] = 1;
	else
	{
		while (visited[indx] != false)
		{
			if (arr[indx].key == key)
				return;
			else
			{
				j++;
				indx += j;
				indx %= sz;
			}
		}
		return;
	}
}

template <typename K, typename Q>
void hashtable<K, Q>::little_sieve()
{
	int primes[100001] = { 0 };
	for (int i = 2; i < 100001; i++)
	{
		if (primes[i] == 0)
		{
			for (int j = i + i; j < 100001; j += i)
				primes[j] = 1;
			if (i >= 7)
				v.push_back(i);
		}
	}
}

template <typename K, typename Q>
void hashtable<K, Q>::set_values()
{
	for (int i = 0; i < sz; i++)
	{
		visited[i] = 0;
		deletion[i] = 0;
	}
}
template <typename K, typename Q>
void hashtable<K, Q> ::expand()
{
	int capacity = next_prime();
	int len = sz;
	sz = capacity;
	MyStruct *temp_arr = new MyStruct[capacity];
	int *temp_visited = new int[capacity];
	int *temp_deletion = new int[capacity];
	memset(temp_visited, 0, capacity * sizeof(temp_visited));
	memset(temp_deletion, 0, capacity * sizeof(temp_deletion));
	int current;
	Q value;
	K key_test;
	int state;
	for (int i = 0; i < len; i++)
	{
		if (visited[i])
		{
			key_test = arr[i].key;
			current = hashing(key_test);
			value = arr[i].value;
			temp_arr[current].value = value;
			temp_arr[current].key = arr[i].key;
			state = visited[i];
			temp_visited[current] = state;
		}
		if (deletion[i] == 1)
			temp_deletion[current] = 1;
	}
	delete[]arr;
	delete[]visited;
	delete[]deletion;
	arr = temp_arr;
	visited = temp_visited;
	deletion = temp_deletion;
}
template <typename K, typename Q>
int hashtable<K, Q> ::next_prime()
{
	stop++;
	return v[stop];
}
template <typename K, typename Q>
bool hashtable<K, Q>::isEmpty()
{
	if (elements != 0)
		return false;
	return true;
}
template <typename K, typename Q>
Q hashtable<K, Q>::get(K key)
{
	long long indx = hashing(key);
	int j = 0;
	if (arr[indx].key == key&& deletion[indx] == 0)
		return arr[indx].value;
	else
	{
		while (visited[indx] != false)
		{
			if (arr[indx].key == key && deletion[indx] == 0)
				return arr[indx].value;
			else
			{
				j++;
				indx += j;
				indx %= sz;
			}
		}
		return arr[indx].value;
	}
}


template <typename K, typename Q>
unsigned int hashtable<K, Q> ::hashing(K key)
{
	int test;
	string temp;
	if (typeid(key).name() == typeid(test).name())
	{
		stringstream ss;
		ss << key;
		ss >> temp;
	}
	else
		temp = key;
	unsigned int hash = 0;

	for (int i = 0; i < temp.size(); i++)
	{
		hash = ((hash << 5) ^ (hash >> 27)) ^ temp[i];
	}
	hash %= sz;
	return hash;
}
template <typename K, typename Q>
int hashtable<K, Q> ::prob_hashing(K x, int y)
{
	int indx = (hashing(x) + y) % sz;
	return indx;
}
template <typename K, typename Q>
void hashtable<K, Q>::put(K key, Q s)
{
	int collision = 0;
	int index;
	double alpha = elements / (double)sz;
	bool vs = false, dl = false;
	if (alpha > 0.5)
	{
		expand();
	}
	while (true)
	{
		index = prob_hashing(key, collision);
		if ((visited[index] == 0 || deletion[index] == 1) ||(visited[index]==1 && arr[index].key==key ) )
		{
			if (visited[index] == 0)
				vs = true;
			if (deletion[index] == 1)
				dl = true;
			arr[index].value = s;
			arr[index].key = key;
			if(!(visited[index] == 1 && arr[index].key == key))
				elements++;
			if (vs)
				visited[index] = 1;
			if (dl)
				deletion[index] == 0;
			break;
		}
		else
			collision++;
	}
}

template <typename K, typename Q>
hashtable<K, Q>::~hashtable()
{
	delete[]arr;
	delete[]deletion;
	delete[]visited;
}
