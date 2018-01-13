#pragma once

#include <iostream>
#include <string>
#include "linkedlist.cpp"
#include "Stack.cpp"
#include "Queue.cpp"
#include "Vector.cpp"
#include "Unordered_map.cpp"
#include "Segsum.cpp"
#include "Segmin.cpp"
#include "Segmax.cpp"
#include "AVL_tree.cpp"
#include "Int_tries.h"
#include "Sparse.h"
class ExpertDS
{
	char choice;
	int enter;
	int sz;
public:
	ExpertDS();
	void apply_functions();
	void immutable();
	void memory_important();
	void add_remove();
	void middle();
	void key_value();
	//void LIFO_FIFO();
	~ExpertDS();
};

