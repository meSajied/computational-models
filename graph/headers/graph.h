#include <iostream>
#include <list>
#include <vector>
using namespace std;

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

class Graph{
protected:
	int vertecies;
	vector<list<int>> adj;
	
public:
	Graph();
	Graph(int vertecies);
	void addEdge(int u, int v);
	void BFS(int source);
};

#endif //UNTITLED_GRAPH_H
