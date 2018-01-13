#pragma once
class sparse_table
{

	long double log_res;
	int column;
public:
	int **minimum_Query;
	sparse_table(int[], int);
	int minimum(int low, int high, int[]);
	~sparse_table(void);
};

