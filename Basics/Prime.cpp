#include<bits/stdc++.h>
using namespace std;
int is_prime(int n)
{
  int i;
  if(n == 0)
     return false;
  if(n == 1)
     return true;
  for(i = 2; i <= n / 2; ++i){
      if(n % i == 0){
          return false;
          break;
      }
  }
  return true;
}
