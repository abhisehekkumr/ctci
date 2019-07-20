/*
     given two sortred array merge array b into a, where a has suffcient memory
*/

#include<iostream>
using namespace std;

int mergeArray(int arr1[], int arr2[], int n, int m){
     int index = n + m -1;
     int a = n-1;
     int b = m-1;

     while(b >= 0){
          if(arr1[a] > arr2[b]){

               arr1[index] = arr1[a];
               a--;
               index--;
          }

          else{
               arr1[index] = arr2[b];
               b--;
               index--;
          }
     }
     return n+m;
}

int main(){
     int n,m;
     cin >> n >> m;

     int arr1[n+m], arr2[m];
     for(int i = 0; i < n; i++)
          cin >> arr1[i];
     for(int i = 0; i <m; i++)
          cin >> arr2[i];

     int index = mergeArray(arr1,arr2,n,m);
     for(int i = 0; i < index; i++)
          std::cout << arr1[i] << ' ';
     std::cout << '\n';
}
