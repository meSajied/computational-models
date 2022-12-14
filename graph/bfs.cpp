#include "headers/bfs.h"

BFS::BFS() {

}

BFS::BFS(int vertecies) {
	this->vertecies = vertecies;
	adj.resize(vertecies);
}

void BFS::add_edge(int u, int v) {
	adj[u].push_back(v);
  adj[v].push_back(u);
}

void BFS::treverse(int source) {
	vector<int> visited;
	visited.resize(vertecies, false);

	visited[source] = true;

	list<int> queue;
	queue.push_back(source);

	while(!queue.empty()) {
		source = queue.front();
		printf("%d\n", source);
		queue.pop_front();

		for(auto adjacent : adj[source]) {
			if(!visited[adjacent]) {
				visited[adjacent] = true;
				queue.push_back(adjacent);
			}
		}
	}
}