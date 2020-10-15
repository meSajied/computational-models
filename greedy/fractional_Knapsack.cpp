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
    vector <int> *items;
    vector <int> *item_weights;
    vector <int> *item_values;
    const int *KNAPSACK_CAPACITY;

    int knapsack(){
        vector <int> *items;
        vector <int> *item_weights;
        vector <int> *item_values;
        vector <int> item_density;
        const int *KNAPSACK_CAPACITY = this->KNAPSACK_CAPACITY;

        items = this->items;
        item_weights = this->item_weights;
        item_values = this->item_values;

        for (auto &i: *items){
            item_density.at(i) = (int)(item_values->at(i) / item_weights->at(i));
        }
        

        sort(*item_density.begin(), *item_density.end(), 0);

        for(int weight = 0; weight < items->size(); weight++){
            int total_weight = 0;

        }

        return 0;
    }

public:
    int print_selected_items(){
        knapsack();
        return 0;
    }

    void get_items(vector<int>*items, vector<int>*item_weights, 
        vector<int>*item_values, int *KNAPSACK_CAPACITY){
        this->items = items;
        this->item_weights = item_weights;
        this->item_values = item_values;
        this->KNAPSACK_CAPACITY = KNAPSACK_CAPACITY;
    }
};