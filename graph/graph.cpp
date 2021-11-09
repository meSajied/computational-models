//
// Created by me_sajied on 09/11/2021.
//

#include "headers/graph.h"
#include <iostream>
#include <vector>
using namespace std;

void Graph::add_edge(vector<int> adj[],
                        int first_vertex, int second_vertex) {
	adj[first_vertex].push_back(second_vertex);
	adj[second_vertex].push_back(first_vertex);
}

void Graph::print_graph(vector<int> adj[], int V) {
	for(int i = 0; i < V; i++) {
		for(auto x: adj[i]) {
			cout << x << endl;
		}
	}
}