#include "graph/headers/dfs.h"

void DFS::treverse(int source) {
	vector<bool> visited;
	visited.resize(vertecies, false);
	visited[source] = true;
	
	cout << source << endl;

	for(auto adjecent: adj[source]) {
		if(!visited[adjecent]) {
			DFS::treverse(adjecent);
		}
	}
}