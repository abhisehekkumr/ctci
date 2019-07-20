/*
     given directed graph find out wheather there exits path between two nodes
*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

bool dfs(int **edges, int n, bool *visited, int start, int end){
     if(start == end)
          return true;

     visited[start] = true;
     for(int i = 0; i < n; i++){
          if(edges[start][i]){
               if(visited[i])
                    continue;
               if(dfs(edges,n,visited,i,end))
                    return true;
          }
     }
     return false;
}

bool hasPath(int **edges, int n, int start, int end){
     bool *visited = new bool[n];
     for(int i = 0; i < n; i++)
          visited[i] = false;
     return dfs(edges,n,visited,start,end);
}

bool dfs_list(unordered_map<int,vector<int>> &m, bool *visited, int n, int start, int end){
     if(start == end)
          return true;
     visited[start] = true;
     for(int i = 0; i < m[start].size(); i++){
          if(!visited[i]){
               if(dfs_list(m,visited,n,i,end))
                    return true;
          }
     }
     return false;
}

bool findPath(unordered_map<int,vector<int>> &m,int n, int start, int end){
     bool *visited = new bool[n];
     for(int i = 0; i < n; i++)
          visited[i] = false;
     return dfs_list(m,visited,n,start,end);
}

int main(){
     int n ,e;
     cin >> n >> e;

     int **edges = new int*[n];
     for(int i = 0; i < n; i++){
          edges[i] = new int[n];
          for(int j = 0; j < n; j++)
               edges[i][j] = 0;
     }

     unordered_map<int,vector<int>> m;

     for(int i = 0; i < e; i++){
          int f,s;
          cin >> f >> s;
          edges[f][s] = 1;
          m[f].push_back(s);
     }

     int start, end;
     cin >> start >> end;

     if(findPath(m,n,start,end))
          std::cout << "yes list" << '\n';
     else
          std::cout << "no list" << '\n';

     if(start == end){
          std::cout << "yes" << '\n';
          return 0;
     }

     if(edges[start][end]){
          std::cout << "yes" << '\n';
          return 0;
     }

     if(hasPath(edges,n,start,end))
          std::cout << "yes" << '\n';
     else
          std::cout << "no" << '\n';
     return 0;
}
