#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Items{
    int items;
    int item_weights;
    int item_values;
};


class FractionalKnapsack{
private:
    vector<int>&items;
    vector<int>item_weights;
    vector<int>item_values;
    final const int MAX_WEIGHT;

    int knapsack(){
        items = this->items;
        item_weights = this->item_weights;
        item_values = this->item_values;
        vector <float> item_density;

        item_density = (item_values/item_weights);
        *max_heap(item_density.begin(), item_density.end());

        return 0;
    }

public:
    int print_selected_items(){
        knapsack();
        return 0;
    }

    void get_items(vector<int>&items, vector<int>&item_weights, 
        vector<int>&item_values, int MAX_WEIGHT){
        this->items = items;
        this->item_weights = item_weights;
        this->item_values = item_values;
        this->MAX_WEIGHT = MAX_WEIGHT;
    }
}