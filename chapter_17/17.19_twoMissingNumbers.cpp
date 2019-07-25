/*
     given number 1 to n exactly once find the missing two
*/
#include<iostream>
#include<unordered_map>
using namespace std;

//O(n*n) solution
void printMissingTwoNumbers(int arr[], int n){
     int m = n + 2;
     int sum = (m*(m+1))/2;
     for(int i = 0; i < n; i++)
          sum = sum - arr[i];

     for(int i = 1; i <= n+2; i++){
          bool found = true;
          for(int j = 0; j < n; j++){
               if(arr[j] == i){
                    found = false;
                    break;
               }
          }

          bool print = true;
          if(found){
               int diff = sum - i;
               for(int j = 0; j < n; j++){
                    if(arr[j] == i){
                         print = false;
                         break;
                    }
               }

               if(print)
                    std::cout << i << " " << sum - i << '\n';
                    break;
          }
     }
}

// O(n) time and space complexity
void missingNumbers(int arr[], int n){
     unordered_map<int,bool> map;
     int m = n + 2;
     int sum = (n*(n+1))/2;
     //std::cout << sum << '\n';
     for(int i = 0; i <  n - 2; i++){
          map[arr[i]] = true;
          sum -= arr[i];
     }
     for(int i = 1; i <= n; i++){
          if(map.count(i) == 0 && map.count(sum-i) == 0){
               std::cout << i << " " << sum - i << '\n';
               break;
          }
     }
}

void printOptimal(int arr[], int n){
     int x = 0;

     for(int i = 0; i < n - 2; i++)
          x = x^arr[i];

     for(int i = 1; i <= n; i++)
          x = x^i;

     int bit = x & ~(x-1);

     int first = 0, second = 0;

     for(int i = 0; i < n-2; i++){
          if(bit & arr[i])
               first = first^arr[i];
          else
               second = second^arr[i];
     }

     for(int i = 1; i <= n; i++){
          if(i & bit)
               first = first ^ i;
          else
               second = second ^ i;
     }
     std::cout << first << " " << second << '\n';
}

int getSum(int arr[], int n){
     int sum = 0;
     for(int i = 0; i < n; i++)
          sum += arr[i];
     return sum;
}

void goodApproach(int arr[], int n){
     int m = n+2;
     int first = 0;
     int second = 0;
     int sum = (m*(m+1))/2 - getSum(arr,n);
     int diff = sum/2;
     for(int i = 0; i < n; i++){
          if(arr[i] <= diff)
               first = first ^ arr[i];
          else
               second = second ^ arr[i];
     }

     for(int i = 1; i <= diff; i++)
          first = first ^ i;
     for(int i = diff+1; i <= n; i++)
          second = second^i;
     std::cout << first << " " << second << '\n';
}

int main(){
     int n;
     cin >> n;

     int arr[n-2];
     for(int i = 0; i < n-2; i++)
          cin >> arr[i];
     printMissingTwoNumbers(arr,n-2);
     missingNumbers(arr,n);
     printOptimal(arr,n);
     goodApproach(arr,n-2);
}
