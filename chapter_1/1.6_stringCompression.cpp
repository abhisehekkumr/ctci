/*
     given single replace consecutive character with character and count
*/
#include<iostream>
using namespace std;

// O(n*n) solution because for concatenation
string compressedString(string str){
     if(str.size() == 0 || str.size() == 1)
          return str;
     int count = 0;
     string ans = "";
     for(int i = 0; i < str.size(); i++){
          count++;
          if(str[i] != str[i+1]){
               if(count > 1){
                    ans += str[i];
                    int number = char((int)'0' + count);
                    ans += (char)number;
               }
               else
                    ans += str[i];
               count = 0;
          }
     }
     return ans;
}

int main(){
     string str;
     cin >> str;
     std::cout << compressedString(str) << '\n';
}
