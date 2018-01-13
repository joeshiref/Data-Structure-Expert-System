#pragma once
#include <iostream>
class Nose {
public:
	long long v;
	int count;
	Nose*z, *o;
	Nose();
};
class ll_tire {
	Nose * root, *emshe;
public:
	ll_tire();
	void search_node(long long input);
	void insert(long long input);
	void del(long long input);
	int get_freq(long long input);
	void free_memory(Nose * cur);
	~ll_tire();
};