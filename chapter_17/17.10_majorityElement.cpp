/*
     find the majority element from array that appears more than half times
*/

#include<iostream>
#include<unordered_map>
using namespace std;


// constant space but O(n*n) time complexity
int majorityElement(int arr[], int n){
     int count = 0;
     for(int i = 0; i < n; i++){
          int count = 0;
          for(int j = i; j < n; j++)
               if(arr[i] == arr[j])
                    count += 1;
          if(count > n/2)
               return arr[i];
     }
     return -1;
}

// O(n) but O(n) space compare
int majorityElementBetter(int arr[], int n){
     unordered_map<int,int> map;
     for(int i = 0; i < n; i++){
          map[arr[i]]++;
          if(map[arr[i]] >= n/2)
               return arr[i];
     }
     return -1;
}


// O(n) and constant space algo called boyer moore
int majorityElementBoyerMoore(int arr[], int n){
     int count = 0;
     int element;

     for(int i = 0; i < n; i++){
          if(count == 0){
               element = arr[i];
               count += 1;
          }
          else if(element == arr[i])
               count += 1;
          else
               count -= 1;
     }

     count = 0;
     for(int i = 0; i < n; i++){
          if(element == arr[i])
               count += 1;
     }

     if(count > n/2)
          return element;
     return -1;
}
int main(){
     int n;
     cin >> n;

     int arr[n];

     for(int i = 0; i < n; i++)
          cin >> arr[i];

     std::cout << majorityElement(arr,n) << '\n';
     std::cout << majorityElementBetter(arr,n) << '\n';
     std::cout << majorityElementBoyerMoore(arr,n) << '\n';
}
