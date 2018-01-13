#pragma once
#include "hashtable.h"
#include "hashtable.cpp"

template <typename K, typename Q>
class Unordered_map
{
	hashtable<K, Q>mp;

public:
	void insert(K, Q);
	void Remove(K);
	Q Get(K key);
	bool isempty();
	//~Unordered_map();
};

