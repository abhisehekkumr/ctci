/*
     given 2D matrix find path from top left to bottom right, where 0 in cell means
     that path is blocked
*/

#include<iostream>
using namespace std;

bool solve(int **grid, int **path, int n, int m, int i, int j){

     if(i+1 == n && j+1 == m){
          std::cout << "path" << '\n';
          path[i][j] = 1;
          for(int i = 0; i < n; i++){
               for(int j = 0; j < m; j++)
                    std::cout << path[i][j] << ' ';
               std::cout << '\n';
          }
          return true;
     }

     if(i >= n || j >= m)
          return false;

     if(grid[i][j] == 0)
          return false;

     if(path[i][j] == 1)
          return false;

     path[i][j] = 1;
     
     if(solve(grid,path,n,m,i+1,j))
          return true;

     if(solve(grid,path,n,m,i,j+1))
          return true;

     path[i][j] = 0;
     return false;
}

void printPath(int **grid, int n, int m){
     int **path = new int*[n];
     for(int i = 0; i < n; i++){
          path[i] = new int[m];
          for(int j = 0; j < m; j++)
               path[i][j] = 0;
     }

     solve(grid,path,n,m,0,0);
}

int main(){
     int r,c;
     cin >> r >> c;

     int **grid = new int*[r];
     for(int i = 0; i < r; i++){
          grid[i] = new int[c];
          for(int j = 0; j < c; j++)
               cin >> grid[i][j];
     }

     printPath(grid,r,c);
}
