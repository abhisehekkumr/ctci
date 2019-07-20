/*
     implement N queens
*/

#include<iostream>
using namespace std;

bool isSafe(int **arr, int n, int row, int col){

     // checking horizontally
     for(int i = 0; i < n; i++){
          if(arr[row][i] == 1)
               return false;
     }

     // checking vertically
     for(int i = 0; i < n; i++){
          if(arr[i][col] == 1)
               return false;
     }

     // left diagonal up
     for(int i = 0; i < n; i++){
          if(row - i >= 0 && col - i >= 0 && arr[row-i][col-i] == 1)
               return false;
          if(row + i < n && col + i < n && arr[row + i][col + i] == 1)
               return false;
          if(row - i >= 0 && col + i < n && arr[row-i][col+i] == 1)
               return false;
          if(row + i < n && col - i >= 0 && arr[row + i][col-i] == 1)
               return false;
     }
     return true;
}

bool solve(int **arr, int n, int row){
     if(row == n){
          for(int i = 0; i < n; i++){
               for(int j = 0; j < n; j++)
                    std::cout << arr[i][j] << ' ';
               std::cout << '\n';
          }
          std::cout << '\n';
          return true;
     }

     for(int i = 0; i < n; i++){
          if(isSafe(arr,n,row,i)){
               arr[row][i] = 1;
               solve(arr,n,row+1);
          }
          arr[row][i] = 0;
     }
     return false;
}

void queens(int n){
     int **arr = new int*[n];
     for(int i = 0; i < n; i++){
          arr[i] = new int[n];
          for(int j = 0; j < n; j++)
               arr[i][j] = 0;
     }

     solve(arr,n,0);
}

int main(){
     int n;
     cin >> n;
     queens(n);
}
