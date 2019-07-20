/*
     given array of both -ve and +ve numbers find largest contiguous sum
*/
#include<iostream>
#include<climits>
using namespace std;

// time complexity is O(n*n)
int largestSum(int arr[], int n){
     int max = INT_MIN;
     int sum = 0;
     for(int i = 0; i < n; i++){
          sum = 0;
          for(int j = i; j < n; j++){
               sum += arr[j];
               max = max > sum ? max : sum;
          }
     }
     return max;
}

// kadnes algo, O(n)
int kednes(int arr[], int n){
     int max = arr[0];
     int sum = 0;

     for(int i = 0; i < n; i++){
          sum += arr[i];
          if(max < sum)
               max = sum;
          if(sum < 0)
               sum = 0;
     }
     return max;
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     std::cout << largestSum(arr,n) << '\n';
     std::cout << kednes(arr,n) << '\n';
}
