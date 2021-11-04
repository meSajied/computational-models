//#include <vector>
//using namespace std;

#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H


class Adjacent {
public:
    void add_edge(vector<int>adj[], int first_vertex, 
            int second_vertex);

    void print_graph(vector<int> adj[], int V);
};


#endif