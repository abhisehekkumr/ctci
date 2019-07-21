/*
     array of numbers from 0  to n, find the one missing number, where we cannot
     get the exact number a[i] from array but we can get jth bit of a[i]
*/

#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

int power(int base, int n){
     int res = 1;
     while(n){
          if(n & 1)
               res = res*base;
          base = base*base;
          n = n >> 1;
     }
     return res;
}

int getBit(int number, int j){
     int bit = number & (1 << j);
     if(bit == 0)
          return 0;
     return 1;
}

// time complexity is O(n log n)
int missingNumber(int arr[], int n){
     unordered_map<int,int> map;
     for(int i = 0; i < n; i++){
          int number = 0;
          for(int j = 0; j < 32; j++){
               int bit = getBit(arr[i],j);
               if(bit)
                    number = number + (1 << j);
          }
          map[number]++;
     }
     for(int i = 0; i <= n; i++){
          if(map.count(i))
               continue;
          return i;
     }
     return 0;
}

// outer loop will excute constant time thus it is O(n)
int missingNumberOptimal(int arr[], int n){
     queue<int> q;

     for(int i = 0; i < n; i++)
          q.push(arr[i]);

     int k = 0;
     for(int i = 0; i < 32; i++){
          if(q.empty())
               return k;

          int zeros = 0;
          int ones = 0;
          int m = q.size();
          for(int j = 0; j < m; j++){
               int number = q.front();
               q.pop();

               if(getBit(number,i))
                    ones++;
               else
                    zeros++;
               q.push(number);
          }

          int bit = 0;
          if(n%2 == 1 && zeros > ones)
               bit = 1;
          if(n%2 == 0 && zeros > ones)
               bit = 1;

          if(bit)
               k = k + (1 << i);

          // removing numbers
          for(int j = 0; j < m; j++){
               int number = q.front();
               q.pop();
               int bit_i = getBit(number,i);
               if(bit_i == bit)
                    q.push(number);
          }
     }
     return k;
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     std::cout << missingNumber(arr,n) << '\n';
     std::cout << missingNumberOptimal(arr,n) << '\n';
}
