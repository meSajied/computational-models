#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

#define lg long
#define llg long long

void solve_problem();
void read_input_files_if_needed();
void compute_tests(int);
void compute_test();

int main() {
  read_input_files_if_needed();
  solve_problem();
  
  return 0;
}

void read_input_files_if_needed() {
  #ifdef READ_FILE
  freopen("testcases", "r", stdin);
  #endif

  return;
}

void solve_problem() {
  int tests;
  scanf("%d", &tests);
  compute_tests(tests);

  return;
}

void compute_tests(int tests) {
  while(tests--) {   
    compute_test();
  }

  return;
}

void compute_test() {
  int a=0,b=0;
  scanf("%d%d", &a, &b);
/*
  if (a==1 || b==1) {
    int res = a*b;
    res *= res;
    printf("%d\n", a*a*b*b);
    return;
  }else if(a/2 !=0 || b/2 !=0) {
    printf("%d\n", a*b);
    return;
  }*/

  int res = 0;
  res = (a / 2) * b;
  printf("%d\n", res);

  return;
}