#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum-ii/

void combinationSum2(int target, int i  , vector<int> &temp, vector<int>& candidates, vector<vector<int>> &st) {
	if (target == 0 ) {
		st.push_back(temp);
		return;
	}
	for (int j = i; j < candidates.size(); j++) {
		if (j > i and candidates[j] == candidates[j - 1])continue; //reason of adding this is simply to avoid the repeatitive elements but make sure to add i>ind which helps to check whether we are adding the value of another index (next one) or addding the value of same index
		if (candidates[j] > target) break; //since if we require some value which makes target as 0 but we have value that is greater than the target (current) which may leads the value to the negative so to avoid that make sure to add the checks so that we don't push the unwanted value.
		temp.push_back(candidates[j]);
		combinationSum2(target - candidates[j], j + 1, temp, candidates, st);
		temp.pop_back();//backtracking of the function
	}
}
