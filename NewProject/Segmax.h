#pragma once
#include <algorithm>
#include <iostream>
using namespace std;
template <typename Q>
class Segmax
{
	Q *tree;
	int len;
public:
	Segmax(int);
	Q *arr;
	void build(int, int, int);
	Q temp(int,int,int,int,int);
	Q query(int, int);
	void temp_2(int, int, int, int, Q);
	void update_element(int, Q);
};

