/*
     given array return its power set
*/

#include<iostream>
#include<vector>
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

int getPowerSet(int **result, int arr[], int n){

     if(n == 0){
          result[0][0] = 0;
          return 1;
     }

     int count = getPowerSet(result, arr+1,n-1);

     for(int i = 0; i < count; i++){
          int length = result[i][0];
          for(int j = length+1; j > 0; j--)
               result[i + count][j] = result[i][j-1];
          result[i + count][0] = length+1;
          result[i + count][1] = arr[0];
     }
     return 2*count;
}

void printSets(int result[], int arr[], int n, int index = 0){
     if(n == 0){
          for(int i = 0; i < index; i++)
               std::cout << result[i] << ' ';
          std::cout << '\n';
          return;
     }

     printSets(result,arr+1,n-1,index);
     result[index] = arr[0];
     printSets(result,arr+1,n-1,index+1);
}

void powersetBitMasking(int arr[], int n){
     int total = power(2,n);

     for(int mask = 0; mask < total; mask++){
          int number = mask;
          int index = 0;
          while(number){
               if(number & 1)
                    std::cout << arr[index] << ' ';
               index += 1;
               number = number >> 1;
          }
          std::cout << '\n';
     }
}

vector<vector<int>> getpowersetBitMasking(int arr[], int n){
     int total = power(2,n);
     vector<vector<int>> v;
     for(int mask = 0; mask < total; mask++){
          int number = mask;
          vector<int> set;
          int index = 0;
          while(number){
               if(number & 1)
                    set.push_back(arr[index]);
               index += 1;
               number = number >> 1;
          }
          v.push_back(set);
     }
     return v;
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++){
          cin >> arr[i];
     }

     int **powerset = new int*[power(2,n)];
     for(int i = 0; i < power(2,n); i++){
          powerset[i] = new int[n+1];
     }

     int count = getPowerSet(powerset,arr,n);

     for(int i = 0; i < count; i++){
          for(int j = 1; j <= powerset[i][0]; j++)
               std::cout << powerset[i][j] << ' ';
          std::cout << '\n';
     }

     std::cout << "printing power sets" << '\n';
     int *result = new int[n];
     printSets(result,arr,n);

     std::cout << "bit masking" << '\n';
     powersetBitMasking(arr,n);

     std::cout << "printing sets from vector" << '\n';
     vector<vector<int>> v = getpowersetBitMasking(arr,n);
     for(int i = 0; i < v.size(); i++){
          for(int j = 0; j < v[i].size(); j++)
               std::cout << v[i][j] << ' ';
          std::cout << '\n';
     }
}
