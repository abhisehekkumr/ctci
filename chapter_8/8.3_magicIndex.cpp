/*
     given sorted array find the magic index where magic index is A[i] = i
*/

#include<iostream>
using namespace std;

int magicIndex(int arr[], int n){

     for(int i = 0; i < n; i++){
          if(arr[i] == i)
               return i;
     }
     return -1;
}

// for unique element better approach
int magicIndexUnique(int arr[], int n){

     for(int i = 0; i < n;){
          if(arr[i] == i)
               return i;
          if(arr[i] <= 0)
               i++;
          else if(arr[i] <= i)
               i++;
          else
               i = arr[i];
     }
     return -1;
}

// using binary search approach
int magicIndexBinarySearch(int arr[], int start , int end){
     if(end < start)
          return -1;

     int mid = (start + end)/2;
     if(mid == arr[mid])
          return mid;
     int left = magicIndexBinarySearch(arr,start,mid-1);
     if(left != -1)
          return left;
     return magicIndexBinarySearch(arr,mid+1,end);
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     std::cout << magicIndex(arr,n) << '\n';
     std::cout << magicIndexUnique(arr,n) << '\n';
     std::cout << magicIndexBinarySearch(arr,0,n-1) << '\n';
}
