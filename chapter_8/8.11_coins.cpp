/*
     given coins and n find how many ways we can form n
*/

#include<iostream>
using namespace std;

int ways(int arr[], int size, int value, int *result, int index = 0){

     if(value == 0){
          for(int i = 0; i < index; i++)
               std::cout << result[i] << ' ';
          std::cout << '\n';
          return 1;
     }

     if(value < 0)
          return 0;

     if(size == 0)
          return 0;
     result[index] = arr[0];
     int ans1 = ways(arr,size,value-arr[0],result,index+1);
     int ans2 = ways(arr+1,size-1,value,result,index);
     return ans1 + ans2;
}

int helper(int *arr, int size, int value, int *result, int **dp, int index = 0){
     if(value == 0){
          for(int i = 0; i < index; i++)
               std::cout << result[i] << ' ';
          std::cout << '\n';
          return 1;
     }
     if(value < 0)
          return 0;

     if(size == 0)
          return 0;
     if(dp[size][value] > -1)
          return dp[size][value];
     result[index] = arr[0];
     int ans1 = helper(arr,size,value-arr[0],result,dp,index+1);
     int ans2 = helper(arr+1,size-1,value,result,dp,index);
     dp[size][value] = ans1 + ans2;
     return dp[size][value];
}

int waysDP(int arr[], int size, int value, int *result){
     int **dp = new int*[size+1];
     for(int i = 0; i <= size; i++){
          dp[i] = new int[value+1];
          for(int j = 0; j <= value; j++)
               dp[i][j] = -1;
     }
     std::cout << "from dp solution" << '\n';
     return helper(arr,size,value,result,dp);
}

int main(){
     int arr[] = {1,5,10,25};
     int value;
     cin >> value;
     int *result = new int[50];
     std::cout << ways(arr,4,value,result) << '\n';
     std::cout << waysDP(arr,4,value,result) << '\n';
}
