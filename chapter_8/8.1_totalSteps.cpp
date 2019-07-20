/*
     A child is hopping staircase and he can jump only 1, 2 or 3 steps
     thus count the minumum steps to reach at top
*/

#include<iostream>
using namespace std;

inline int min(int a, int b){
     return a < b ? a : b;
}


// O(n) time comlexity and O(n) space comlexity
int solve(int n, int *dp){
     if(n == 0 || n == 1)
          return 1;

     if(n < 0)
          return 0;

     if(dp[n] > -1)
          return dp[n];
     dp[n] = solve(n-1,dp) + solve(n-2,dp) + solve(n-3,dp);
     return dp[n];
}

int minStepsDP(int n){
     int *dp = new int[n+1];
     for(int i = 0; i <= n; i++)
          dp[i] = -1;
     return solve(n,dp);
}


// this function is pure recursion resulting in O(3^n) time comlexity
int minSteps(int n){
     if(n == 0 || n == 1)
          return 1;
     if(n < 0)
          return 0;
     return minSteps(n-1) + minSteps(n-2) + minSteps(n-3);
}

int main(){
     int n;
     cin >> n;
     std::cout << minStepsDP(n) << '\n';
     std::cout << minSteps(n) << '\n';
}
