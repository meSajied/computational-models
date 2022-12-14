#include <iostream>
#include <list>
#include <map>
#include <vector>

#define BLACK 1
#define WHITE -1

using namespace std;

#ifndef UNTITLED_DFS_H
#define UNTITLED_DFS_H

class DFS {
protected:
  int verticies;
	vector<int> dfs_num;
	vector<pair<int int>> adj;
	
public:
	DFS();
	DFS(int vertecies);
	void add_edge(int u, int v);
  void dfs_visit(int source);
};

#endif
