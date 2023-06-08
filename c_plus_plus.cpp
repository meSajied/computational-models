#include <string>
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

#define lg long
#define llg long long

void read_input_files_if_needed();
void compute_tests(int);
void compute_test(int);

int main() {
  read_input_files_if_needed();

  int tests;
  scanf("%d", &tests);

  assert(tests <= 100);
  assert(tests >= 1);

  compute_tests(tests);
  
  return 0;
}

void read_input_files_if_needed() {
  #ifdef READ_FILE
  freopen("testcases", "r", stdin);
  freopen("output", "w", stdout);
  #endif

  return;
}

void compute_tests(int tests) {
  while(tests--) {
    int N;
    scanf("%d", &N);

    assert(N <= 100);
    assert(N >= 1);
    
    compute_test(N);
  }

  return;
}

void compute_test(int N) {
    assert(N <= 100);
    assert(N >= 1);

    int left_dist = N - 1;
    int right_dist = 100 - N;

    if(left_dist < right_dist) {
      printf("LEFT\n");
    } else {
      printf("RIGHT\n");
    }

  return;
}