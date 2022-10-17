#include "headers/graph.h"

Graph::Graph() {

}

Graph::Graph(int vertecies) {
	this->vertecies = vertecies;
	adj.resize(vertecies);
}

void Graph::addEdge(int u, int v) {
	adj[u].push_back(v);
  adj[v].push_back(u);
}
