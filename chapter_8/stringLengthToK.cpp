/*
     given string print all string of length to k
*/

#include<iostream>
#include<string>
using namespace std;


int stringsLengthToK(string arr, int k, string output[]){
     if(k == 1){
          for(int i = 0; i < arr.size(); i++)
               output[i] = arr[i];
          return arr.size();
     }

     int count = stringsLengthToK(arr,k-1,output);

     for(int i = 0; i < count; i++){
          int jump = count;
          string ans = output[i];
          output[i] = arr[0] + output[i];
          for(int j = 1; j < arr.size(); j++){
               output[jump + i] = arr[j] + ans;
               jump += count;
          }
     }
     return count*arr.size();
}

int main(){
     string arr;
     int k = 3;
     cin >> arr;

     string output[100];
     int count = stringsLengthToK(arr,k,output);
     for(int i = 0; i < count; i++){
          std::cout << output[i] << '\n';
     }
}
