/*
given 2D matrix rotate it by 90 clockwise
*/

#include<iostream>
using namespace std;

void transpose(int **arr, int n, int m){
     for(int i = 0; i < n; i++){
          for(int j = 0; j <= i && j < m; j++){
               int temp = arr[i][j];
               arr[i][j] = arr[j][i];
               arr[j][i] = temp;
          }
     }
}

void rotateBy90(int **arr, int n, int m){
     transpose(arr,n,m);
     int k = m-1;
     for(int j = 0; j < m/2; j++){
          for(int i = 0; i < n; i++){
               int temp = arr[i][j];
               arr[i][j] = arr[i][k];
               arr[i][k] = temp;
          }
     }
}

// most optimal solution
/*
     1) first element which is also a top always lies at current layer and i th column
     2) bottom left :
*/
void optimalRotate(int **arr,int n, int m){
     for(int layer = 0; layer < n/2; layer++){
          int last = n-1-layer;
          for(int i = layer; i < last; i++){
               int offset = i - layer;
               int top = arr[layer][i];
               // copy bottom left to top left
               arr[layer][i] = arr[last-offset][layer];
               // copy bottom right to bottom left
               arr[last-offset][layer] = arr[last][last-offset];
               // top right to bottom right
               arr[last][last-offset] = arr[layer + offset][last];
               arr[layer + offset][last] = top;
          }
     }
}

int main(){
     int n,m;
     cin >> n >> m;

     int **arr = new int*[n];
     for(int i = 0; i < n; i++)
          arr[i] = new int[m];

     for(int i = 0; i < n; i++)
     for(int j = 0; j < m; j++)
     cin >> arr[i][j];

     optimalRotate(arr,n,m);
     std::cout << "transpose" << '\n';
     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++)
               std::cout << arr[i][j] << ' ';
          std::cout << '\n';
     }

     for(int i = 0; i < n; i++)
          delete [] arr[i];
     delete [] arr;
     return 0;
}

/*
1 2 3 4
4 5 6 7
8 9 10 11
12 13 14 15
*/
