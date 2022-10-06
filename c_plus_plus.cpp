#include "graph/headers/bfs.h"


int main() {
	BFS::Graph(4);
	BFS g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	g.treverse(2);

	return 0;
}
