#include "headers/graph.h"

Graph::Graph() {

}

Graph::Graph(int vertecies) {
	this->vertecies = vertecies;
}

void Graph::addEdge(int u, int v) {
	adj.resize(vertecies);
	adj[u].push_back(v);
  adj[v].push_back(u);
}