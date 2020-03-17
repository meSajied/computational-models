#include<bits/stdc++.h>
using namespace std;


int knapSack(int capacity, int weight[], int price[], int n){

	int i, w;
	int matrix[n+1][capacity+1];
	//n = sizeof(price)/ sizeof(price[0]);

	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= capacity; ++w) {

			if(i == 0 || w == 0)
				matrix[i][w] = 0;
			else if(weight[i-1] <= w)
				matrix[i][w] = max(price[i-1]+matrix[i-1][w-weight[i-1]], matrix[i-1][w]);
			else
				matrix[i][w] = matrix[i-1][w];

		}

	}
	return matrix[n][capacity];

}

int main(){

	int price[] = {60, 100, 120};
	int weight[] = {10, 20, 30};
	int  capacity = 50;
	int n = sizeof(price)/sizeof(price[0]);
	//cout << n;
	printf("%d", knapSack(capacity, weight, price, n));
	return 0;
}
