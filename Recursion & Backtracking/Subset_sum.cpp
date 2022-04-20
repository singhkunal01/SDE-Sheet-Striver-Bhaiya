// https://practice.geeksforgeeks.org/problems/subset-sums2234/1
#include <bits/stdc++.h>
using namespace std;

void helper(int i, vector<int> &arr, vector<int> &res, int n, int sum) {
	if (i == n) {
		res.push_back(sum);
		return;
	}
	helper(i + 1, arr, res, n, sum + arr[i]);
	helper(i + 1, arr, res, n, sum);
}

vector<int> subsetSums(vector<int> arr, int N)
{
	sort(arr.begin(), arr.end());
	vector<int> res;
	helper(0, arr, res, N, 0);
	return res;
}
