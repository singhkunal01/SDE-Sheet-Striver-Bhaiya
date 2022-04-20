#include <bits/stdc++.h>
using namespace std;

#define newl "\n"
#define fr(x, a, b) for (int x = a; x < b; x++)
#define sz(x) ((int)(x).size())
#define speedIO() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)          //flush the buffer


typedef long long ll;
typedef long long int lli;

class Solution {
private:
public:
	vector<int> missingAndRepeating(vector<int>&arr) {
		int n = arr.size();
		lli sum1 = (n * (n + 1)) >> 1;
		lli sum2 = (n * (n + 1) * (2 * n + 1)) / 6;
		lli missing = 0 , repeat = 0;
		for (int &i : arr) {
			sum1 -= lli(i);
			sum2 -= lli(i) * lli(i);
		}
		missing = (sum1 + sum2 / sum1) / 2;
		repeat = missing - sum1;
		return {(int)missing, (int)repeat};
	}
};

int main() {
	int n;
	cin >> n;
	vector<int>arr(n);
	for (int &i : arr) cin >> i;
	Solution obj;
	vector<int> res = obj.missingAndRepeating(arr);
	cout << "Missing : " << res[0] << " & Repeated : " << res[1];
}


//singhkunal01