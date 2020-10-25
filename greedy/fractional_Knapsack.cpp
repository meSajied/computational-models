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
    vector <int> items;
    vector <int> item_weights;
    vector <int> items_values;
    int ITEM_CAPACITY;

public:
    int knapsack(){
        vector <Items> items = this->items;
        vector <Items> item_weights = this->item_weights;
        vector <Items> items_values = this->item_values;
        vector <Items> ITEM_CAPACITY = ITEM_CAPACITY;

        vector <float> item_density;
        vector <int>::iterator itr;

        for(int i = 1; i <= items.size(); i++){
            items.push_back(i);
            item_weights.push_back(i);
            items_values.push_back(i)
        }

        for(itr = items.begin(); itr != items.end(); itr++){
            item_density[itr] = items_values[itr] / item_weights[itr];
        }

        sort(item_density.begin(), item_density.end());

        return 0;
    }

    int print_value(){
        return 0;
    }

    void get_data(vector<int>&items, vector<int>&item_weights, 
                    vector<int>&item_values, int& ITEM_CAPACITY){
        this->items = items;
        this->item_weights = item_weights;
        this->items_values = item_values;
        this->ITEM_CAPACITY = ITEM_CAPACITY;
    }
};

int main(){
    Items items;
    items.
    return 0;
}