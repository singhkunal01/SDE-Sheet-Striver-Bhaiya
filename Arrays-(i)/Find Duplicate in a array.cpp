#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> &arr, int n) {
// Write your code here.
	int slow = arr[0], fast = arr[0];
//this is solved using tortoise and hare method in which we move slow by one step and fast by 2 steps until we donot get first collision then we move both by 1 step until we get the another second collision hence return the slow or fast;
	do {
		slow = arr[slow];
		fast = arr[arr[fast]];
	} while (slow != fast);
//here we get the first collision now point the fast at first element and slow remains same wherever it was
	fast = arr[0];
	while (slow != fast) {
		slow = arr[slow];
		fast = arr[fast];
	}
	return slow;
}

//call the function in ur main program by inputting number of vertices , edges and taking adjacency list as Input Format.

© singhkunal01;