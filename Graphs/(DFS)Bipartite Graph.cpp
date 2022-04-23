/*................................CYCLE DETECTION BY DFS................................*/
#include <bits/stdc++.h>
using namespace std;

bool isCyclicDFS(int node, int parent, vector<int> &vis, vector<int> adj[]) {
	vis[node] = 1;                               //first mark the current node as visited
	for (auto eachNode : adj[node]) {
		if (!vis[eachNode]) {
			/* INTUTION: First check whether the node is visited or not ,if the node is not visited then call the same function and if the current node is visited then
			 go and check the parent that its parent is same as the current node or not if not then return true (means it has a cycle) */
			if (isCyclicDFS(eachNode, node, vis, adj))
				return true;
		}
		else if (eachNode != parent)
			return true;
	}
	return false;
}


bool checkForCycleInAGraph( vector<int> adj[], int vert) {
	vector<int> vis(vert, 0);
	for (int node = 0; node < vert; node++) {
		if (!vis[node])
			if (isCyclicDFS(node, -1, vis, adj))
				return true;
	}
	return false;
}