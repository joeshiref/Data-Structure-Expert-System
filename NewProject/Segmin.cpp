#pragma once
#include "Segmin.h"


template<typename Q>
Segmin<Q>::Segmin(int length)
{
	len = length;
	arr = new Q[length];
	tree = new Q[4 * length];
	for (int i = 0; i < len; i++)
		cin >> arr[i];
	build(1, 0, (length - 1));
}

template <typename Q>
void Segmin<Q>::build(int node, int start, int end)
{
	if (start == end)
		tree[node] = arr[start];
	else
	{
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		tree[node] = min(tree[2 * node], tree[2 * node + 1]);
	}
}
template<typename Q>
Q Segmin<Q>::temp(int node, int start, int end, int left, int right)
{
	if (end < left || start > right)
		return INT_MAX;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	int p1 = temp(2 * node, start, mid, left, right);
	int p2 = temp(2 * node + 1, mid + 1, end, left, right);
	return min(p1, p2);
}
template<typename Q>
Q Segmin<Q>::query(int left, int right)
{
	left--;
	right--;
	return temp(1, 0, len - 1, left, right);
}

template<typename Q>
void Segmin<Q>::temp_2(int node, int start, int end, int index, Q val)
{
	if (index > end || index < start)
		return;
	if (start == end)
		tree[node] = val;
	int mid = (start + end) / 2;
	temp_2(2 * node, start, mid, index, val);
	temp_2(2 * node + 1, mid + 1, end, index, val);
	tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
template<typename Q>
void Segmin<Q>::update_element(int index, Q value)
{
	index--;
	temp_2(1, 0, len - 1, index, value);
}
