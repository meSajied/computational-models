#include<bits/stdc++.h>
using namespace std;
long long int bigMod(int Number, int Power, int Moduler)
{
     if(Power == 0)
          return 1;
     else if(Power == 2)
          return ((Number % Moduler)*(bigmod(Number, Power-1, Moduler))) % Moduler;
     else{
          long long int c = bigMod(Number, Power/2, Moduler);
          return ((c%Moduler)*(c%Moduler))%Moduler;
     }
}
int main()
{
     //int q;
//     bitset<int>q;
     int a, b, c;
     cin >> a >> b >> c;
     cout << bigMod(a, b, c);
}
