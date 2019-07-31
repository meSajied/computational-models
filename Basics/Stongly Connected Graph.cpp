#include<bits/stdc++.h>
using namespace std;
stack<int>s;
int n, a, b, e, mat[100][100], mat2[100][100], visited[1000], cur, i, j;
void DFS( int cur)
{
    for(i = 0; i < n; i++)
    if(mat[cur][i] && visited[i] == 0){
        visited[i] = 1;
        DFS(i);
        s.push(i);
    }
}
void DFS2(int cur)
{
    cout << cur;
    for(i = 0; i < n; i++)
    if(mat2[cur][i] == 1 && visited[i] == 1){
        visited[i] = 0;
        DFS2(i);
    }
}
void SCC()
{
    int cur;
    cout << "\nSCC:\n";
    while(!s.empty()){
        cur = s.pop();
        if(visited[cur] == 1){
            visited[cur] = 0;
            DFS2(cur);
            cout << endl;
        }
    }
}
int main()
{
    cin >> n >> e;
    for(i = 0; i <n; i++){
        visited[i] = 0;
        for(j = 0; j < n; j++)
            mat[i][j] = 0;
    }
    for(i = 0; i < e; i++){
        cin >> a >> b;
        mat[a][b] = 1;
    }
    DFS(0);
}
