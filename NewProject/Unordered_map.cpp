#pragma once
#include "Unordered_map.h"


template <typename K, typename Q>
void Unordered_map<K, Q>::insert(K k, Q v)
{
	mp.put(k, v);
}
template <typename K, typename Q>
void Unordered_map<K, Q>::Remove(K k)
{
	mp.remove(k);
}

template <typename K, typename Q>
Q Unordered_map<K, Q>::Get(K k)
{
	return mp.get(k);
}
template <typename K, typename Q>
bool Unordered_map<K, Q>::isempty()
{
	return mp.isEmpty();
}

//template <typename K, typename Q>
//Unordered_map<K, Q>::~Unordered_map()
//{
//	mp.~hashtable();
//}
