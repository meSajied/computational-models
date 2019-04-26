#include<bits/stdc++.h>
using namespace std;

#define maximum 10001
int arr[maximum];
int tree[maximum*4];

void segment(int node, int begin, int end){

     if(begin == end){
          tree[node] = arr[begin];
          return;
     }
     int left = node*2;
     int right = (node*2) + 1;
     int middle = (begin + end) / 2;
     segment(left, begin, middle);
     segment(right, middle+1, end);
     tree[node] = tree[begin] + tree[end];
}

int query(int node, int begin, int end, int i, int j){

     if(i > end || j < begin)
          return 0;
     if(begin >= i && end <= j)
          return tree[node];
     int left = node*2;
     int right = (node*2) + 1;
     int middle = (begin + end) / 2;
     int num1 = query(left, begin, middle, i, j);
     int num2 = query(right, middle+1, end, i, j);
     return num1 + num2;
}

void update(int node, int begin, int end, int i, int newvalue){

     if(i > end || i < begin)
          return;
     if(begin >= i && end <= i){
          tree[node] = newvalue;
          return;
     }
     int Left = node * 2;
     int Right = node * 2 + 1;
     int middle = (begin + end) / 2;
     update(Left, begin, middle, i, newvalue);
     update(Right, middle + 1, end, i, newvalue);
     tree[node] = tree[Left] + tree[Right];
}

int main(){

     //cout << "Hello World";
     int test, i, N, q, arr[1000], n1, n2;
     cin >> test;
     for(i = 1; i <= test; i++){
          cin >> N >> q;
          for(i = 1; i <= N; i++){
               cin >> arr[i];
          }
          segment(1, 1, N);
          printf("Case %d:\n", i);
          for(i = 0; i < q; i++){
               cin >> n1 >> n2;
               printf("%d\n", query(1, 1, N, n1, n2));
          }
     }
}
