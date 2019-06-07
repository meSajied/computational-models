#include<bits/stdc++.h>
using namespace std;

typedef struct{
     int Weight, Price;
}Object;
int main()
{
     int i, w, N, mat[100][100], Capacity;
     Object Obj[100];
     cin >> N;
     for(i = 1; i <= N; i++){
          cin >> Obj[i].Weight >> Obj[i].Price >> Capacity;
     }
     for(i = 1; i <= N; i++){
          mat[i][0] = 0;
     }
     for(i = 1; i <= N; i++)
          for(w = 1; w <= Capacity; w++){
               if(Obj[i].Weight > w)
                    mat[i][w] = mat[i-1][w];
               else
                    mat[i][w] = max(mat[i-1][w], mat[i-1][w-Obj[i].Weight]+Obj[i].Price);
          }
     cout << mat[N][Capacity] << endl;
}
