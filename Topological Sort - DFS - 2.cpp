#include<iostream>

using namespace std;

int mat[100][100],visited[100],n,e,k,st[100],fn[100];

void DFS(int cur)
{
    int i;
    visited[cur]=i;
    for(i=0; i<n; ++i)
    {
        if(mat[cur][i]&&visited[i]==0)
        {
            st[i]=++k;
            DFS(i);
            fn[i]==++k;
        }
    }
}

void topologicalsort()
{
    int ind[100];
    for(int i=0; i<n; ++i)
    {
        ind[i]=i;
    }
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            if(fn[i]<fn[j])
            {
                int temp;
                temp=st[i];
                st[i]=st[j];
                st[j]=temp;

                temp=fn[i];
                fn[i]=fn[j];
                fn[j]=temp;

                temp=ind[i];
                ind[i]=ind[j];
                ind[j]=temp;
            }

        }
    }
    for(int i=0; i<n; ++i)
    {
        cout<<ind[i]<<" ";
    }
}

int main()
{
    cin>>n>>e;
    for(int i=0; i<n; ++i)
    {
        visited[i]=0;
    }
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            mat[i][j]=0;
        }
    }
    for(int i=0; i<e; ++i)
    {
        int a,b;
        cin>>a>>b;
        mat[a][b]=1;
    }
    k=0;
    st[1]=++k;
    DFS(1);
    fn[1]=++k;
    topologicalsort();
    return 0;
}

