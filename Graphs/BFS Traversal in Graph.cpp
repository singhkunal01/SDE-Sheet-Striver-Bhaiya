vector<int> bfsOfGraph(int vert, vector<int> adj[]) {
	vector<int> res;
	vector<bool> vis(vert + 1, false);
	for (int i = 1; i <= vert; i++) {
//check whether the node is visited or not if not then do this further
		if (!vis[i]) {
			queue<int> qu;
			qu.push(i);
			vis[i] = true;//mark that node as visited.
			while (!qu.empty()) {
				int node = qu.front();
				qu.pop();
				res.push_back(node);//save that node in the result.
				//now put all the adjacent nodes of the current node in the queue.
				for (auto &adjNode : adj[node]) {
					//again check whether the adjacent node is visited or not
					if (!vis[adjNode]) {
						qu.push(adjNode);
						vis[adjNode] = true;//mark as visited
					}
				}
			}
		}
	}
	return res;
}


//to use you can also use this solve function and simply call it in your main function.
void solve() {
	int vert, edges;
	cin >> vert >> edges;
	vector<int> adjList[vert + 1];
	InputAdjacencyList(vert, edges, adjList);//this function is called to make the adjacency list refer to CODE 1. REPRESENTATION IN GRAPHS ,there you get this code.
	vector<int> res = bfsOfGraph(vert, adjList);
	for(auto x:res) cout<<x<<" ";

}
