/*
     given array of numbers and letters find the largest subarray that has
     equal number of letters and numbers
*/

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

inline int max(int a, int b){
     return a > b ? a : b;
}

// time complexity is O(n*n*n)
int largestSubarray(string str){
     int ans = 0;
     int start = 0, end = 0;

     for(int i = 0; i < str.size(); i++){
          for(int j = i; j < str.size(); j++){
               int letters = 0, numbers = 0;
               for(int k = i; k <= j; k++){
                    if(str[k] >= 'A' && str[i] <= 'z')
                         letters++;
                    else
                         numbers++;
               }

               if(numbers == letters && ans < (numbers + letters)){
                    ans = letters + numbers;
                    start = i;
                    end = j;
               }
          }
     }

     if(start == end)
          return ans;

     for(int i = start; i <= end; i++)
          std::cout << str[i];
     std::cout << '\n';
     return ans;
}

// time complexity is O(n*n)
int largestSubarrayOptimal(string str){

     int arr[2][str.size()];
     for(int i = 0; i < str.size(); i++){

          if(str[i] >= 'A' && str[i] <= 'z'){
               if(i == 0){
                    arr[0][i] = 1;
                    arr[1][i] = 0;
               }
               else{
                    arr[0][i] = arr[0][i-1] + 1;
                    arr[1][i] = arr[1][i-1];
               }
          }
          else{
               if(i == 0){
                    arr[1][i] = 1;
                    arr[0][i] = 0;
               }else{
                    arr[1][i] = arr[1][i-1]+1;
                    arr[0][i] = arr[0][i-1];
               }
          }
          //std::cout << arr[0][i] << " " << arr[1][i] << '\n';
     }

     int ans = 0;
     for(int i = 0; i < str.size(); i++){
          if(arr[0][i] == arr[1][i])
               ans = max(ans,arr[1][i]);

          int diff_start = arr[0][i] - arr[1][i];
          for(int j = i+2; j < str.size(); j++){
               int diff_end = arr[0][j] - arr[1][j];
               //std::cout << arr[0][i] << " " << arr[1][i] << " " << arr[0][j] << " " << arr[1][j] << ' ';
               //std::cout << diff_start << " " << diff_end << '\n';
               if(diff_start == diff_end){
                    ans = max(ans, j - i);
                    //std::cout << i+1 << " " << j << " " << diff_end << " " << diff_start <<  '\n';
               }
          }
     }
     return ans;
}

// O(n) approach 
int mostOptimal(string str){
     int n = str.size();
     int arr[2][str.size()];
     for(int i = 0; i < str.size(); i++){

          if(str[i] >= 'A' && str[i] <= 'z'){
               if(i == 0){
                    arr[0][i] = 1;
                    arr[1][i] = 0;
               }
               else{
                    arr[0][i] = arr[0][i-1] + 1;
                    arr[1][i] = arr[1][i-1];
               }
          }
          else{
               if(i == 0){
                    arr[1][i] = 1;
                    arr[0][i] = 0;
               }else{
                    arr[1][i] = arr[1][i-1]+1;
                    arr[0][i] = arr[0][i-1];
               }
          }
          //std::cout << arr[0][i] << " " << arr[1][i] << '\n';
     }

     int diff[n];
     for(int i = 0; i < n; i++)
          diff[i] = arr[0][i] - arr[1][i];

     int ans = 0;
     unordered_map<int,int> map;
     for(int i = 0; i < n; i++){
          if(map.count(diff[i])){
               ans = max(ans, i - map[diff[i]]);
               //map[diff[i]] = i;
          }
          else
               map[diff[i]] = i;
     }
     return ans;
}

int main(){
     string str;
     cin >> str;
     std::cout << largestSubarray(str) << '\n';
     std::cout << largestSubarrayOptimal(str) << '\n';
     std::cout << mostOptimal(str) << '\n';
}
/*
     aaaa11a11aa1aa1aaaaa
*/
