#include <iostream>
#include <list>
#include <vector>
using namespace std;

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

class Graph{
	int vertecies; 
	vector<list<int>> adj;

public:
	Graph(int vertecies);
	void addEdge(int u, int v);
	void BFS(int source);
};
#endif //UNTITLED_GRAPH_H
