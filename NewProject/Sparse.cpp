#include "Sparse.h"
#include<cmath>
#include <algorithm> 
#include <Windows.h> 
#define M_LOG2E 1.44269504088896340736 //log2(e)
inline long double log_2(const long double x) {
	return  log(x) * M_LOG2E;
}
sparse_table::sparse_table(int arr[], int n)
{
	log_res = n;
	log_res = log_2(log_res);
	column = log_res;
	minimum_Query = new int*[n];
	for (int i = 0; i < n; ++i)
		minimum_Query[i] = new int[column + 1];
	for (int i = 0; i<n; i++)
	{
		minimum_Query[i][0] = i;
	}

	for (int j = 1; pow(2, j) <= n; j++)
	{
		for (int i = 0; i + pow(2, j) - 1<n; i++)
		{
			int power = pow(2, j - 1);
			if (arr[minimum_Query[i][j - 1]]<arr[minimum_Query[i + power][j - 1]])
				minimum_Query[i][j] = minimum_Query[i][j - 1];
			else
				minimum_Query[i][j] = minimum_Query[i + power][j - 1];

		}
	}
}
int sparse_table::minimum(int low, int high, int arr[])
{
	int L = high - low + 1;
	log_res = log_2(L);
	column = log_res;
	long long	power = pow(2, column);
	return min(arr[minimum_Query[low][column]], arr[minimum_Query[low + L - power][column]]);

}
sparse_table::~sparse_table(void)
{
}
