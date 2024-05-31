#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Function to compute GCD of two numbers
int compute_gcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

// Function to compute prefix and suffix GCD arrays
void prefix_suffix_gcd(const vector<int>& arr, vector<int>& prefix_gcd, vector<int>& suffix_gcd) {
    int n = arr.size();
    prefix_gcd[0] = 0;
    suffix_gcd[n + 1] = 0;
    
    for (int i = 1; i <= n; ++i) {
        prefix_gcd[i] = compute_gcd(prefix_gcd[i - 1], arr[i - 1]);
    }
    
    for (int i = n; i >= 1; --i) {
        suffix_gcd[i] = compute_gcd(suffix_gcd[i + 1], arr[i - 1]);
    }
}

// Function to count the number of strong indices
int count_strong_indices(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix_gcd(n + 1);
    vector<int> suffix_gcd(n + 2);
    
    prefix_suffix_gcd(arr, prefix_gcd, suffix_gcd);
    int overall_gcd = prefix_gcd[n];
    
    int strong_indices_count = 0;
    
    for (int i = 1; i <= n; ++i) {
        int gcd_excluding_i;
        if (i == 1) {
            gcd_excluding_i = suffix_gcd[2];
        } else if (i == n) {
            gcd_excluding_i = prefix_gcd[n - 1];
        } else {
            gcd_excluding_i = compute_gcd(prefix_gcd[i - 1], suffix_gcd[i + 1]);
        }
        
        if (gcd_excluding_i != overall_gcd) {
            ++strong_indices_count;
        }
    }
    
    return strong_indices_count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        
        cout << count_strong_indices(A) << '\n';
    }

    return 0;
}
