#pragma once
#include "Segsum.h"


template<typename Q>
Segsum<Q>::Segsum(int length)
{
	len = length;
	arr = new Q[length];
	tree = new Q[4 * length];
	for (int i = 0; i < len; i++)
		cin >> arr[i];
	build(1, 0, (length - 1));
}

template <typename Q>
void Segsum<Q>::build(int node, int start, int end)
{
	if (start == end)
		tree[node] = arr[start];
	else
	{
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}
template<typename Q>
Q Segsum<Q>::temp(int node, int start, int end, int left, int right)
{
	if (right < start || end < left)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	int p1 = temp(2 * node, start, mid, left, right);
	int p2 = temp(2 * node + 1, mid + 1, end, left, right);
	return (p1 + p2);
}
template<typename Q>
Q Segsum<Q>::query(int left, int right)
{
	left--;
	right--;
	return temp(1, 0, len - 1, left, right);
}
template<typename Q>
void Segsum<Q>::temp_2(int node, int start, int end, int index, Q val)
{
	if (start == end)
	{
		arr[index] += val;
		tree[node] += val;
	}
	else
	{
		int mid = (start + end) / 2;
		if (start <= index && index <= mid)
			temp_2(2 * node, start, mid, index, val);
		else
			temp_2(2 * node + 1, mid + 1, end, index, val);
		tree[node] = tree[2 * node] + tree[2 * node + 1];
		cout << tree[node] << endl;
	}
}
template<typename Q>
void Segsum<Q> ::update_element(int index, Q value)
{
	index--;
	temp_2(1, 0, len - 1, index, value);
}

