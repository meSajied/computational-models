#include <vector>
using namespace std;

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

class Graph {
public:
		void add_edge(vector<int> adj[], int first_vertex,
		              int second_vertex);

		void print_graph(vector<int> adj[], int V);
};


#endif //UNTITLED_GRAPH_H
