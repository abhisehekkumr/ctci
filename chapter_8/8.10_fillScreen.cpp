/*
     given 2D SCREEN and a point fill it with given color
*/

#include<iostream>
using namespace std;

void fillColors(int arr[10][10], int n, int x, int y, int color){
     if(x < 0 || x >= 10 || y < 0 || y >= 10)
          return;

     if(arr[y][x] == 1)
          return;

     arr[y][x] = 1;

     fillColors(arr,n,x-1,y,color);
     fillColors(arr,n,x+1,y,color);
     fillColors(arr,n,x,y-1,color);
     fillColors(arr,n,x,y+1,color);
}

int main(){
     int arr[10][10];
     for(int i = 0; i < 10; i++)
     for(int j = 0; j < 10; j++)
     arr[i][j] = 0;

     fillColors(arr,10,9,5,1);

     std::cout << '\n';
     for(int i = 0; i < 10; i++){
          for(int j = 0; j < 10; j++)
               std::cout << arr[i][j];
          std::cout << '\n';
     }
}
