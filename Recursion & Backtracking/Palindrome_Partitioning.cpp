#include<bits/stdc++.h>
using namespace std;

/*main functions which helps to solve the problem
1 . isPalindrome() to check the whether the substring is palindrome or not and that string is substring which is passed from start to endif
2 . helper() to solve the problem recursively.*/
class solution {
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> path;
		helper(0, s, path, result);
		return result;
	}
	void helper(int ind, string &s, vector<string> &path, vector<vector<string>> &res) {
		if (ind == s.size()) {
			res.push_back(path);
			return;
		}
		for (int i = ind; i < s.size(); i++) {
			if (isPalindrome(s, ind, i)) {
				path.push_back(s.substr(ind, i - ind + 1));
				helper(i + 1, s, path, res);
				path.pop_back();
			}
		}
	}
	bool isPalindrome(string s, int start, int end) {
		while (start <= end) {
			if (s[start] != s[end]) return false;
		}
		return true;
	}
};