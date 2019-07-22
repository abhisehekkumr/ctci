/*
     given a number k find the find the smallest possible kth number whose prime
     factor are either or all are from 3,5,7 and none other
*/
#include<iostream>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

bool isValidNumber(int number){

     for(int i = 2; i <= number; i++){
          bool prime = true;

          for(int j = 2; j < i; j++){

               if(i%j == 0){
                    prime = false;
                    break;
               }
          }

          if(prime){
               //std::cout << i << '\n';
               if(number%i == 0 && (i > 7 || i < 3)){
                    //std::cout << "i : " << i << '\n';
                    return false;
               }
          }
     }
     return true;
}

// O(n*n*n) time compare but it can be reduced to O(n*n*sqrt(n)
int smallestKthNumber(int k){

     int count = 1;
     int i = 3;
     int number = 0;
     //std::cout << 1 << ' ';
     while(count < k){
          if(isValidNumber(i)){
               count += 1;
               number = i;
               //std::cout << number << ' ';
          }
          i++;
     }
     std::cout << '\n';
     std::cout << "ans " << '\n';
     return number;
}

// base O(k*k*k + k log k)
int smallestKthNumberKloop(int k){
     int min = INT_MAX;
     int *arr = new int[k*k*k];
     int j = 0;
     for(int a = 0; a <= k; a++){
          for(int b = 0; b <= k; b++){
               for(int c = 0; c <= k; c++){

                    int ans = (int)pow(7,a) * (int)pow(5,b) * (int)pow(3,c);
                    if(ans <= 0 || (int)pow(7,a) == INT_MAX || (int)pow(5,b) == INT_MAX || (int)pow(3,c) == INT_MAX)
                         ans = INT_MAX;

                    arr[j] = ans;
                    //std::cout << ans << '\n';
                    j++;
               }
          }
     }
     sort(arr,arr + k*k*k);
     //for(int i = 0; i < k; i++)
     //     std::cout << arr[i] << '\n';
     return arr[k-1];
}

int main(){
     int k;
     cin >> k;
     std::cout << smallestKthNumber(k) << '\n';
     //std::cout << isValidNumber(k) << '\n';
     std::cout << smallestKthNumberKloop(k) << '\n';
}
