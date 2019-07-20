/*
     given sorted array find out wheather given element exists, but we don't know
     the side of the array, but we have atIndex(i) which gives -1, if we jump out
     of bound
*/

#include<iostream>
using namespace std;

int n;
int atIndex(int arr[],int i){
     if(i < n)
          return arr[i];
     return -1;
}

// awesome approach for this problem
bool binarySearch(int arr[], int element, int start, int end){
     if(start > end)
          return false;
     int mid = (start + end)/2;
     if(atIndex(arr,mid) == element)
          return true;
     if(atIndex(arr,mid) == -1 || atIndex(arr,mid) > element)
          return binarySearch(arr,element,start,mid-1);
     return binarySearch(arr,element,mid+1,end);
}

bool fastSearch(int arr[], int element){
     int size = 1;
     while(atIndex(arr,size) != -1)
          size *= 2;
     return binarySearch(arr,element,0,size-1);
}

// the most pathetic solution possible which is linear seach over sorted array
bool linearSearch(int arr[], int element){
     int i = 0;
     while(atIndex(arr,i) != -1){
          if(atIndex(arr,i) == element)
               return true;
          i++;
     }
     return false;
}

int main(){
     cin >> n;
     int arr[n];
     for(int i = 0; i < n; i++)
          arr[i] = i + 1;
     int element;
     cin >> element;
     std::cout << linearSearch(arr,element) << '\n';
     std::cout << fastSearch(arr,element) << '\n';
}
