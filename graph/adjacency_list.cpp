#include <vector>
#include "headers/adjacency_list.h"
using namespace std;

void Adjacent::add_edge(vector<int> *adj,
        int first_vertex, int second_vertex) {
    adj[first_vertex].push_back(second_vertex);
    adj[second_vertex].push_back(first_vertex);
}

void Adjacent::print_graph(vector<int> adj[], int V) {
    for(int i = 0; i < V; i++) {
        for(auto x: adj[v]) {
            cout << x << endl;
        }
    }
}