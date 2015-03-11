#include <iostream>
#include <string>
#include <cassert>
#include <map>
#include <vector>

using namespace std;

int countWays(int n);
int DP_countWays(int n, map <int, int> c_w);
int magicFast(int *array, int size);
int magicFast_util(int *array, int start, int end, int size);
vector< vector<int> > get_subsets(vector<int> set);
vector<int> convert_int_set(int k, vector<int> set);

int main(int argc, char const *argv[])
{
	vector<int> set;
	map <int, int> c_w;
	vector< vector<int> > all_subset;
	vector< vector<int> >::iterator iter_ii;
	vector< int > ::iterator iter_jj;

	cout << "learning of dynamic programming and recursion" << endl;
	cout << "countWays(4) = " << countWays(4) << endl;
	cout << "countWays(4, c_w) = " << DP_countWays(4, c_w) << endl;

	set.push_back(1);
	set.push_back(2);
	set.push_back(3);
	set.push_back(4);

	all_subset = get_subsets(set);


	for(iter_ii = all_subset.begin(); iter_ii != all_subset.end(); iter_ii++)
	{
		for(iter_jj=(*iter_ii).begin(); iter_jj!=(*iter_ii).end(); iter_jj++)
		{
			cout << *iter_jj << " ";
		}
		cout << endl;
	}


	// int array[11] = {-10,-5,2,2,2,3,4,7,9,12,13};
	// cout << "magicFast(array) : "<< magicFast(array, 11) << endl;
	return 0;
}

vector< vector<int> > get_subsets(vector<int> set)
{
	vector< vector<int> > all_subset;

	int max = 1 << set.size();

	for(int k = 0; k < max; k++)
	{
		vector<int> sub_set = convert_int_set(k,set);
		all_subset.push_back(sub_set);
	}

	return all_subset;
}

vector<int> convert_int_set(int k, vector<int> set)
{
	vector<int> sub_set;
	int index = 0;
	for(int i = k; i > 0; i >>= 1)
	{
		if((i & 1) == 1)
		{
			sub_set.push_back(set[index]);
		}
		index++;
	}
	return sub_set;
}

/*
int magicFast(int *array, int size)
{
	return magicFast_util(array, 0, size, size);
}

int magicFast_util(int *array, int start, int end, int size)
{
	if(end < start || start < 0 || end >= size)

	int mid = (start + end)/2;
	int mid_elem = array[mid];

	if(mid_elem == mid)
	{
		return mid;
	}


}
*/


int countWays(int n)
{
	if(n < 0) return 0;
	else if(n == 0) return 1;
	else
	{
		return (countWays(n-1) + countWays(n-2) + countWays(n-3));
	}
}

int DP_countWays(int n, map <int, int> c_w)
{
	map <int, int>::iterator i = c_w.find(n);

	if(n < 0)
	{
		// cout << "n < 0" << endl;
		return 0;
	}
	else if(n == 0)
	{
		// cout << "n == 0" << endl;
		return 1;
	}
	else if(i != c_w.end())
	{
		// cout << "c_w[n] > -1" << endl;
		return c_w[n];
	}
	else
	{
		c_w[n] = (DP_countWays(n-1, c_w) + DP_countWays(n-2, c_w) + DP_countWays(n-3, c_w));
		// cout << "c_w[n]" << endl;
		return c_w[n];
	}
}



