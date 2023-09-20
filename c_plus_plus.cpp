#include <string>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

#define lg long
#define llg long long

void solve_problem();
void read_input_files_if_needed();
void compute_tests(int);
void compute_test();

int main() {
  solve_problem();
  
  return 0;
}

void solve_problem() {
  read_input_files_if_needed();

  int tests;
  scanf("%d", &tests);
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
  
  return;
}