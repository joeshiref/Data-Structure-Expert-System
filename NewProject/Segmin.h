#include <algorithm>
#include <iostream>
using namespace std;
#pragma once
template <typename Q>
class Segmin
{
	Q *tree;
	int len;
public:
	Segmin(int);
	Q *arr;
	void build(int, int, int);
	Q temp(int, int, int, int, int);
	Q query(int, int);
	void temp_2(int, int, int, int, Q);
	void update_element(int, Q);
};

