/*
     given rotated sorted array find given element
*/
#include<iostream>
#include<algorithm>
using namespace std;

bool findElement(int arr[], int element, int start, int end){
     if(start > end)
          return false;

     int mid = (start + end)/2;
     if(arr[mid] == element)
          return true;

     if(findElement(arr,element,start,mid-1))
          return true;
     return findElement(arr,element,mid+1,end);
}

bool binarySearch(int arr[], int element, int start, int end){
     if(start > end)
          return false;
     int mid = (start + end)/2;

     if(arr[mid] == element)
          return true;
     if(arr[mid] > element)
          return binarySearch(arr,element,start,mid-1);
     return binarySearch(arr,element,mid+1,end);
}

// again sort element and than find using binary seach result O(n log n) + O(log n)
bool sortAndSearach(int arr[], int n, int element){
     sort(arr,arr+n);
     return binarySearch(arr,element,0,n-1);
}
// O(n) time complexity the most pathetic solution for searching an element in
// array which is nearly sorted, or rotated
bool findElementLinear(int arr[], int n, int element){

     for(int i = 0; i < n; i++){
          if(arr[i] == element)
               return true;
     }
     return false;
}

// time complexity is O(log n)
bool modifiedBinarySearch(int arr[], int element, int start, int end){
     if(start > end)
          return false;
     int mid = (start + end)/2;
     if(arr[mid] == element)
          return true;
     // left part is sorted
     if(arr[start] < arr[mid]){
          if(arr[mid] > element && arr[start] >= element)
               return modifiedBinarySearch(arr,element,start,mid-1);
          return modifiedBinarySearch(arr,element,mid+1,end);
     }

     if(arr[end] > arr[mid]){
          if(arr[end] >= element && arr[mid] < element)
               return modifiedBinarySearch(arr,element,mid+1,end);
          return modifiedBinarySearch(arr,element,start,mid-1);
     }

     // if both left are identicall
     if(arr[mid] == arr[start] || arr[mid] == arr[end]){
          if(arr[mid] == arr[start] && arr[mid] == arr[end]){
               if(modifiedBinarySearch(arr,element,start,mid-1))
                    return true;
               return modifiedBinarySearch(arr,element,mid+1,end);
          }

          if(arr[mid] == arr[start])
               return modifiedBinarySearch(arr,element,mid+1,end);

          if(arr[mid] == arr[end])
               return modifiedBinarySearch(arr,element,start,mid-1);
     }
     return false;
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     int element;
     cin >> element;
     std::cout << findElement(arr,element,0,n-1) << '\n';
     std::cout << findElementLinear(arr,n,element) << '\n';
     std::cout << sortAndSearach(arr,n,element) << '\n';
     std::cout << modifiedBinarySearch(arr,element,0,n-1) << '\n';
}
