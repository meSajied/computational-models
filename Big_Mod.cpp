#include<bits/stdc++.h>
using namespace std;

long long int big_mod(int number, int power, int moduler){
     if(power == 0)
          return 1;
     else if(power == 2)
          return ((number % moduler)*(bigmod(number, power-1, moduler))) % moduler;
     else{
          long long int c = big_mod(number, power/2, moduler);
          return ((c % moduler)*(c % moduler)) % moduler;
     }
}