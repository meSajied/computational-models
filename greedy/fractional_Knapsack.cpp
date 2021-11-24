#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Items{
    int item_value = 0;
    int item_weight = 0;
    float item_density = 0.0;
};

class FractionalKnapsack {
public:
	float TOTAL_VALUE = 0.0;

	void get_data(int values[], int weights[], 
			int WEIGHT, int size) {
		this->WEIGHT = WEIGHT;
		this->size = size;
		
		for (int i = 0; i < size; i++) {
			item[i].item_value = values[i];
			item[i].item_weight = weights[i];
			item[i].item_density = (float)(item[i].item_value) / 
					(float)(item[i].item_weight);
		}		
	}

	void knapsack() {
		sort(item, item+size, greater);

		int current_weight = 0;
		for(int i = 0; i < size; i++) {
			if(current_weight + item[i].item_weight <= WEIGHT) {
				current_weight += item[i].item_weight;
				TOTAL_VALUE += item[i].item_value;
			}

			else {

				TOTAL_VALUE += (WEIGHT-current_weight) 
					* item[i].item_density;
			}
			
		}
		

	}

private:
	int WEIGHT;
	Items item[100];
	int size;

	static bool greater(struct Items r1, struct Items r2) {
		return (r1.item_density > r2.item_density);
		
	}

};

int main() {
    int values[] = {60, 100, 120};
		int weights[] = {10, 20, 30};
		int N = (int)(sizeof(values) / sizeof(values[0]));

		FractionalKnapsack fk;

		fk.get_data(values, weights, 50, N);
		fk.knapsack();

		cout << fk.TOTAL_VALUE << endl;

    return 0;
}