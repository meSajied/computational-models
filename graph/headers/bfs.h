#include <iostream>
#include <map>
#include <list>
#include <vector>
using namespace std;

#ifndef UNTITLED_BFS_H
#define UNTITLED_BFS_H

class BFS{
protected:
	int vertecies;
	vector<list<int>> adj;
	
public:
	BFS();
	BFS(int vertecies);
	void add_edge(int u, int v);
	void treverse(int source);
};

#endif //UNTITLED_BFS_H
