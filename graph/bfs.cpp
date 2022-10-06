#include "headers/bfs.h"

void BFS::treverse(int source) {
  vector<bool> visited;
	visited.resize(vertecies, false);
	visited[source] = true;
	
	list<int> queue;
	queue.push_back(source);

	while(!queue.empty()) {
		source = queue.front();
		cout << source << endl;
		queue.pop_front();

		for(auto adjecent: adj[source]) {
			if(!visited[adjecent]) {
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}
