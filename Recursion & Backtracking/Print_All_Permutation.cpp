#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/permutations/

//normal approach

void generate2(vector<int> &perm, vector<int> &nums, vector<vector<int>> &res, vector<int> vis) {
    if (perm.size() == nums.size()) {
        res.push_back(perm);
        return;
    }
    for (int j = 0; j < nums.size(); j++) {
        if (!vis[j]) {
            perm.push_back(nums[j]);
            vis[j] = 1;
            generate2(perm, nums, res, vis);
            perm.pop_back();
            vis[j] = 0;
        }
    }
}
vector<vector<int>> permute2(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> ds;
    vector<int> vis(nums.size(), 0);
    generate2(ds, nums, res, vis);
    return res;
}

/*----------------------------------------------------------------------------------------------*/

//optimal approach
void generate(int ind , vector<int> &nums, vector<vector<int>> &res) {
    if (ind == nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int i  = ind; i < nums.size(); i++) {
        swap(nums[ind], nums[i]);
        generate(ind + 1, nums, res);
        swap(nums[ind], nums[i]);

    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    generate(0, nums, res);
    return res;
}
