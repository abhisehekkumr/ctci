/*
     given 2D matrix where 0 represents water and any value grater than 0 represents
     land, print size of all ponds in it
*/

#include<iostream>
using namespace std;

int solve(int **arr, int **visited, int n, int m, int i, int j){
     if(i >= n || i < 0 || j < 0 || j >= m)
          return 0;

     if(arr[i][j] != 0)
          return 0;

     if(visited[i][j] == 1)
          return 0;

     visited[i][j] = 1;
     int count = 1;

     count += solve(arr,visited,n,m,i-1,j-1);
     count += solve(arr,visited,n,m,i-1,j);
     count += solve(arr,visited,n,m,i-1,j+1);
     count += solve(arr,visited,n,m,i,j-1);
     count += solve(arr,visited,n,m,i,j+1);
     count += solve(arr,visited,n,m,i+1,j-1);
     count += solve(arr,visited,n,m,i+1,j);
     count += solve(arr,visited,n,m,i+1,j+1);

     return count;
}


// overall time and space complexity O(n*m)
void printpondSizes(int **arr, int n, int m){
     int **visited = new int*[n];
     for(int i = 0; i < n; i++){
          visited[i] = new int[m];
          for(int j = 0; j < m; j++)
               visited[i][j] = 0;
     }

     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
               if(arr[i][j] == 0 && visited[i][j] == 0)
                    std::cout << solve(arr,visited,n,m,i,j) << ' ';
          }
     }
     std::cout << '\n';
}

int main(){
     int n,m;
     cin >> n >> m;

     int **arr = new int*[n];
     for(int i = 0; i < n; i++){
          arr[i] = new int[m];
          for(int j = 0; j < m; j++)
               cin >> arr[i][j];
     }

     printpondSizes(arr,n,m);
}
