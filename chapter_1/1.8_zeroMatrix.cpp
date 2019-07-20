/*
     write a fucntion to make entire column and row equall to 0, if we find once
*/

#include<iostream>
using namespace std;

// good approach but contains extra O(n*m) space
// good but not efficient in space though
void makeZeros(int **arr, int n, int m){
     bool **visited = new bool*[n];
     for(int i = 0; i < n; i++){
          visited[i] = new bool[m];
          for(int j = 0; j < m; j++)
               visited[i][j] = false;
     }
     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
               if(arr[i][j] == 0 && !visited[i][j]){
                    for(int k = 0; k < m; k++){
                         arr[i][k] = 0;
                         visited[i][k] = true;
                    }
                    for(int k = 0; k < n; k++){
                         arr[k][j] = 0;
                         visited[k][j] = true;
                    }
               }
          }
     }
}

// O(N) space complexity best approach
// fucking good approach
void optimal(int **arr, int n, int m){
     bool row[n];
     bool columns[m];
     for(int i = 0; i < n; i++)
          row[i] = false;
     for(int i = 0; i < m; i++)
          columns[i] = false;
     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
               if(row[i] || columns[j])
                    continue;
               if(arr[i][j] == 0 && !row[i] && !columns[j]){
                    for(int k = 0; k < n; k++)
                         arr[k][j] = 0;
                    for(int k = 0; k < m; k++)
                         arr[i][k] = 0;
                    row[i] = true;
                    columns[j] = true;
               }
          }
     }
}

// most optimal solution constant space complexity
void mostOptimal(int **arr, int n, int m){
     bool row = false;
     bool column = false;

     for(int j = 0; j < m; j++){
          if(arr[0][j] == 0){
               row = true;
               break;
          }
     }
     for(int i = 0; i < n; i++){
          if(arr[i][0] == 0){
               column = true;
               break;
          }
     }
     for(int i = 1; i < n; i++){
          for(int j = 1; j < m; j++){
               if(arr[i][j] == 0){
                    arr[i][0] = 0;
                    arr[0][j] = 0;
               }
          }
     }
     for(int j = 1; j < m; j++){
          if(arr[0][j] == 0){
               for(int k = 0; k < n; k++)
                    arr[k][j] = 0;
          }
     }
     for(int i = 1; i < n; i++){
          if(arr[i][0] == 0){
               for(int k = 0; k < m; k++)
                    arr[i][k] = 0;
          }
     }
     if(row){
          for(int j = 0; j < m; j++)
               arr[0][j] = 0;
     }
     if(column){
          for(int i = 0; i < n; i++)
               arr[i][0] = 0;
     }
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
     mostOptimal(arr,n,m);
     std::cout << "resultant matrix" << '\n';
     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++)
               std::cout << arr[i][j] << ' ';
          std::cout << '\n';
     }
}
