/*
     return maximum amount that can be taken where we cannot pick alternate amoounts
*/

#include<iostream>
using namespace std;

int maxMinutes(int arr[], int n){
     if(n <= 0)
          return 0;
     int add = arr[0] + maxMinutes(arr+2,n-2);
     int leav = maxMinutes(arr+1,n-1);
     return max(add, leav);
}

int helper(int arr[], int n, int *dp){
     if(n <= 0)
          return 0;
     if(dp[n] > -1)
          return dp[n];
     int add = arr[0] + helper(arr+2,n-2,dp);
     int leave = helper(arr+1,n-1,dp);
     dp[n] = max(add,leave);
     return dp[n];
}

int maxMinutesDP(int arr[], int n){
     int *dp = new int[n+1];
     for(int i = 0; i <= n; i++)
          dp[i] = -1;
     return helper(arr,n,dp);
}

int main(){
     int n;
     cin >> n;
     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     std::cout << maxMinutes(arr,n) << '\n';
     std::cout << maxMinutesDP(arr,n) << '\n';
}
