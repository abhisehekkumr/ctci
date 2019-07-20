/*
     given two planks one is shorter and other is longer build a diving board
     of k planks and print all possible combinations
*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


// run time complexity is O(2^k), which is never acceptable and space complexity
// is O(k)
void print(int arr[], int k, int shorter, int longer, int index = 0){
     if(k == 0){
          for(int i = 0; i < index; i++)
               std::cout << arr[i] << ' ';
          std::cout << '\n';
          return;
     }
     arr[index] = shorter;
     print(arr,k-1,shorter,longer,index+1);
     arr[index] = longer;
     print(arr,k-1,shorter,longer,index+1);
}

// O(n) time and space complexity solution
void printResult(int k, int shorter, int longer){
     unordered_map<int,int> m;
     std::vector<int> v;
     for(int i = shorter; i <= k; i++){
          int n = k - i;
          int sum = i*i + n*n;
          m[sum] = sum;
          v.push_back(sum);
          //std::cout << sum << " sum " << '\n';
     }

     unordered_map<int,int> :: iterator it;
     for(it = m.begin(); it != m.end(); it++)
          std::cout << it->second << '\n';
}

int main(){
     int k,shorter,longer;
     cin >> shorter >> longer >> k;
     int arr[k];
     //print(arr,k,shorter,longer);
     printResult(k,shorter,longer);
}
