#include <string>
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

#define lg long
#define llg long long

void solve_leetcode();
void leetcode_method();
void solve_problem();
void read_input_files_if_needed();
void compute_tests(int);
void compute_test();

int main() {
  solve_leetcode();
  solve_problem();
  
  return 0;
}

void solve_leetcode() {
  leetcode_method();

  return;
}

void leetcode_method() {
  read_input_files_if_needed();
  
  return;
}

void solve_problem() {
  read_input_files_if_needed();

  int tests;
  scanf("%d", &tests);

  assert(tests <= 100);
  assert(tests >= 1);

  compute_tests(tests);

  return;
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
    compute_test();
  }

  return;
}

void compute_test() {
  int N;
  scanf("%d", &N);

  assert(N <= 100);
  assert(N >= 1);
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