#include "headers/graph.h"
using namespace std;

Graph::Graph(int vertecies) {
	this->vertecies = vertecies;
	adj.resize(vertecies);
}

void Graph::addEdge(int u, int v) {
	adj[u].push_back(v);
  adj[v].push_back(u);
}

void Graph::BFS(int source) {
	vector<bool> visited;
	visited.resize(vertecies, false);

	list<int> queue;

	visited[source] = true;
	queue.push_back(source);

	while(!queue.empty()) {
		source = queue.front();
		cout << source << " ";
		queue.pop_front();

		for(auto adjecent: adj[source]) {
			if(!visited[adjecent]) {
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}
