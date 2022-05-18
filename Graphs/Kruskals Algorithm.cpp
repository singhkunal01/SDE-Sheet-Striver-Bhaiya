#include <bits/stdc++.h>
using namespace std;

/*this whole code is the part of kruskals algorithm*/
int findParent(int node, vector<int>&parent) {
	if (node == parent[node]) return node;
	return findParent(parent[node], parent);
}

void findUnion(int node1, int node2, vector<int> &parent, vector<int> &ranks) {
	node1 = findParent(node1, parent); //find the ultimate parent of both nodes
	node2 = findParent(node2, parent);
	/*	three conditions if the rank of node1 is less than the rank of node2 ,
	if the rank of first is greater than the rank of node2 and if the ranks of boths are equal */
	if (ranks[node1] < ranks[node2]) {
		parent[node1] = node2;
	}
	else if (ranks[node1] > ranks[node2]) {
		parent[node2] = node1;
	}
	else {
		parent[node2] = node1;
		//increase the levels of ranks
		ranks[node1]++;
	}
}

//Kruskals Algorithm
void kruskalAlgorithm(int &cost, vector<vector<int>> &adjList, vector<int> &parent, vector<int> &ranks, vector<pair<int, int>> &mst) {
//iterate over the adjacency list
	for (auto &nodes : adjList) {
		if (findParent(nodes[1], parent) != findParent(nodes[2], parent)) {
			cost += nodes[0];
			mst.push_back({nodes[1], nodes[2]});
			findUnion(nodes[1], nodes[2], parent, ranks);
		}
	}
}


int main() {
	int vert, edges;
	cin >> vert >> edges;
	vector<vector<int>> adjList(edges, vector<int>(3));
	for (int i = 0; i < edges; i++) {
		int node1, node2, weight;
		cin >> weight >> node1 >> node2 ;
		adjList[i] = {weight, node1, node2};
	}
	sort(adjList.begin() , adjList.end());
	vector<int> parent(edges), ranks(edges, 0);
	for (int i = 0; i < edges; i++) parent[i] = i; //initially the all nodes are components of itself
	vector<pair<int, int>> mst;
	int cost = 0;
//call the kruskal algorithm function
	kruskalAlgorithm(cost, adjList, parent, ranks, mst);
	cout << "Total Cose : " << cost << "\n";
	for (auto node : mst) cout << "Draw an Edge From " << node.first << " To " << node.second << "\n";
}

//call the function in ur main program by inputting number of vertices , edges and taking adjacency list as Input Format.

// © singhkunal01