/*
     printing the relative order of the two arrays without changing order
     in wave form
*/
#include<iostream>
using namespace std;

void print(int arr1[], int arr2[], int ans[], int s1, int s2, int index = 0){
     if(s1 == 0 && s2 == 0){
          for(int i = 0; i < index; i++)
               std::cout << ans[i] << ' ';
          std::cout << '\n';
          return;
     }
          
     if(s1){
          ans[index] = arr1[0];
          print(arr1+1,arr2,ans,s1 - 1, s2, index+1);
     }
     if(s2){
          ans[index] = arr2[0];
          print(arr1,arr2+1,ans,s1,s2-1,index+1);
     }
}

int main(){
     int n;
     cin >> n;

     int arr1[n];
     for(int i = 0; i < n; i++)
          cin >> arr1[i];
     int arr2[n];
     for(int i = 0; i < n; i++)
          cin >> arr2[i];
     int ans[2*n];
     print(arr1,arr2,ans,n,n);
}
