#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum/

void combinationSum1(int target, int i, vector<int> &temp, vector<int>& candidates, vector<vector<int>> &res) {
    if (i == candidates.size() ) {
        if (target == 0) {
            res.push_back(temp);
        }
        return;
    }
    if (candidates[i] <= target) {
        temp.push_back(candidates[i]);
        combinationSum1(target - candidates[i], i, temp, candidates, res);
        temp.pop_back();
    }
    combinationSum1(target, i + 1, temp, candidates, res);

}