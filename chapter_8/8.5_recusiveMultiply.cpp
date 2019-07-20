/*
     given two numbers multiply them by adding , subtracting and division but not multiplication
*/

#include<iostream>
using namespace std;

// no improvements what was asked in question
int multiply(int a, int b, int result = 0){
     if(b == 0 || a == 0)
          return result;
     if(b == 1)
          return result + a;
     return multiply(a,b-2, result + a + a);
}

// better approach
int helper(int smaller, int larger){
     if(smaller == 0)
          return 0;
     if(smaller == 1)
          return larger;

     int s = smaller >> 1;
     int side1 = helper(s,larger);
     int side2 = side1;
     if(smaller % 2 == 1)
          side2 = helper(smaller-s,larger);
     return side1 + side2;
}

int multiplyBetter(int a, int b){
     int small = a < b ? a : b;
     int large = a > b ? a : b;
     return helper(small, large);
}


int helperDP(int smaller, int larger, int **dp){

     if(smaller == 0)
          return 0;

     if(smaller == 1)
          return larger;

     if(dp[larger][smaller] > -1)
          return dp[larger][smaller];

     int s = smaller >> 1;

     int side1 = helperDP(s,larger,dp);

     int side2 = side1;

     if(smaller % 2 == 1)
          side2 = side2 + larger;//helperDP(smaller-s,larger,dp);

     dp[larger][smaller] = side1 + side2;

     return dp[larger][smaller];
}

// using dp
int multiplyBetterDP(int a, int b){
     int smaller = a < b ? a : b;
     int larger = a > b ? a : b;

     int **dp = new int*[larger+1];
     for(int i = 0; i <= larger; i++){
          dp[i] = new int[smaller+1];
          for(int j = 0; j <= smaller; j++)
               dp[i][j] = -1;
     }
     return helperDP(smaller,larger,dp);
}
int main(){
     int a = 7;
     int b = 8;
     //cin >> a >> b;
     std::cout << multiply(a,b) << '\n';
     std::cout << multiplyBetter(a,b) << '\n';
     std::cout << multiplyBetterDP(a,b) << '\n';
}
