#include<bits/stdc++.h>
using namespace std;

//helper function which helps to solve the problem
void getPath(int i, int j, vector<vector<int>> &m, int n, vector<string> &res, string mv, vector<vector<int>> &vis) {
//base case
   if (i == n - 1 and j == n - 1) {
      res.push_back(mv);
      return;
   }
//now to get the answer in lexiographical order so we have to move in ascending order like- DLRU

//downward
   if (i + 1 < n and !vis[i + 1][j] and m[i + 1][j] == 1) {
//mark the cell as visited
      vis[i][j] = 1;
      getPath(i + 1, j, m, n, res, mv + 'D', vis);
      vis[i][j] = 0;

   }
//leftward
   if (j - 1 >= 0 and !vis[i][j - 1] and m[i][j - 1] == 1) {
//mark the cell as visited
      vis[i][j] = 1;
      getPath(i, j - 1, m, n, res, mv + 'L', vis);
      vis[i][j] = 0;

   }
//rightward
   if (j + 1 < n and !vis[i][j + 1] and m[i][j + 1] == 1) {
//mark the cell as visited
      vis[i][j] = 1;
      getPath(i, j + 1, m, n, res, mv + 'R', vis);
      vis[i][j] = 0;

   }
//upward
   if (i - 1 >= 0 and !vis[i - 1][j] and m[i - 1][j] == 1) {
//mark the cell as visited
      vis[i][j] = 1;
      getPath(i - 1, j, m, n, res, mv + 'U', vis);
      vis[i][j] = 0;

   }
}

//main function which returns the resultant ans

vector<string> findPath(vector<vector<int>> &m, int n) {
   vector<vector<int>> vis(n, vector<int> (n, 0));
   vector<string> res;
   if (m[0][0] == 1)getPath(0, 0, m, n, res, "", vis);
   return res;
}