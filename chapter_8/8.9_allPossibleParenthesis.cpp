/*
     given n print all possible valide parenthsis of length 2N for ()
*/
#include<iostream>
using namespace std;

void print(int n, int opening = 0, int closing = 0, string ans = ""){
     //std::cout << ans << '\n';
     if(opening == n && closing == n){
          std::cout << ans << '\n';
          return;
     }

     if(opening == closing){
          print(n,opening+1,closing,ans + "(");
          return;
     }

     if(opening == n){
          print(n,opening,closing+1,ans + ")");
          return;
     }

     print(n,opening+1,closing,ans + "(");
     print(n,opening,closing+1,ans+")");
}

int main(){
     int n;
     cin >> n;
     print(n);
}
