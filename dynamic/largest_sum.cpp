#include "headers/largest_sum.h"
#include <algorithm>
using namespace std;

int LargestSum::one_dim(int A[]) {
	int n = sizeof(A)/sizeof(A[0]);
	int sum = 0;
	int ans = 0;

	for(int i = 0; i < n; i++) {
		sum += A[i];
		ans = max(ans, sum);

		if(sum < 0){
			sum = 0;
		}
	}

	return ans;
}