#include <vector>
#include "headers/adjacency_list.h"
using namespace std;

void Adjacent::add_edge(vector<int> *adj,
                        int first_vertex, int second_vertex) {
    adj[first_vertex].push_back(second_vertex);
}
