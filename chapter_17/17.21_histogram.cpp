/*
given array of hills and land find the maximum water that can be saved or
stored
*/

#include<iostream>
#include<climits>
using namespace std;


// whenever we need to find somrthing at left and right at same time then it is
// clear indecation that we have to make left and right array
int maxWater(int arr[], int n){
     int left[n];
     int right[n];

     left[0] = arr[0];
     for(int i = 1; i < n; i++){
          left[i] = max(left[i-1],arr[i]);
     }

     right[n-1] = arr[n-1];
     for(int j = n-2; j >= 0; j--){
          right[j] = max(right[j+1],arr[j]);
     }

     int water = 0;
     for(int i = 0; i < n; i++){
          if(left[i] != 0 && right[i] != 0)
               water += min(left[i], right[i]) - arr[i];
     }
     return water;
}

int findIndexOfMax(int arr[], int start, int end){
     int max = arr[start];
     int index = start;
     for(int i = start; i <= end; i++){
          if(max < arr[i]){
               index = i;
               max = arr[i];
          }
     }
     return index;;
}

int border(int arr[], int start, int end){
     int sum = 0;
     for(int i = start + 1; i < end; i++)
          sum += min(start, end) - arr[i];
     return sum;
}

int volume(int arr[], int start, int end, bool left){
     if(start >= end)
          return 0;
     int sum = 0;

     if(left){
          int max = findIndexOfMax(arr,start,end-1);
          sum += border(arr,start,max);
          sum += volume(arr,start,max,left);
     }
     else{
          int max = findIndexOfMax(arr,start+1,end);
          sum += border(arr,max,end);
          sum += volume(arr,max,end,left);
     }
     return sum;
}

int histogram(int arr[], int n){
     int start = 0;
     int end = n-1;

     int tallest = findIndexOfMax(arr,start,end);
     int leftVolum = volume(arr,start, tallest,true);
     int rightVolume = volume(arr,tallest,end,false);
     return leftVolum + rightVolume;
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     std::cout << maxWater(arr,n) << '\n';
     std::cout << histogram(arr,n) << '\n';
}
