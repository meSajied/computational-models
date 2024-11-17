#include <bits/stdc++.h>
 
using namespace std;

struct Point {
  int x;
  int y;
};


long get_area(vector<int>x, vector<int>y) {
  vector<Point> pnt;
  int sz = x.size();

  for (int i = 0; i < sz; i++) {
    pnt.push_back({x[i], y[i]});
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  int a=0, b=0;

  for (int i = 1; i <= sz; i++) {
    if(x[i] == x[i-1]) {
      a = 1;
    }
  }

  for (int i = 1; i <= sz; i++) {
    if(y[i] == y[i-1]) {
      b = 1;
    }
  }

  if(a==1) {
    pnt
  }
  
  return 0;
}
 
int main() {
  
}