#include "headers/dfs.h"

DFS::DFS() {

}

DFS::DFS(int verticies) {
  this->verticies = verticies;
  adj.resize(verticies, pair<int, int> s);
  dfs_num.resize(verticies, WHITE);
}

DFS::treverse(int source) {

}

DFS::dfs_visit(int source) {
  dfs_num[source] = BLACK;
  printf("%d", source);

  for(int i = 0; i < adj[source].size(); i++) {
    pair<int, int> v = adj[source][i];

    if(dfs_num[v.first] == WHITE) {
      DFS::dfs_visit(v.first);
    } 
  }
}