/*
     given two number add them without using any arithmetic operator
*/

#include<iostream>
using namespace std;

int add(int a, int b){
     int ans = 0;
     int carry = 0;
     bool flag = false;

     if(a < 0 && b < 0){
          flag = true;
          a = (~a);
          a = a | 1;
          b = (~b);
          b = b | 1;
     }
     for(int i = 0; i < 32; i++){
          int bit1 = a & (1 << i);
          int bit2 = b & (1 << i);

          if(bit1 > 0 && bit2 > 0){
               if(carry == 1)
                    ans = ans | (1 << i);
               carry = 1;
          }
          else if(bit1 == 0 && bit2 > 0){
               if(carry == 1){
                    continue;
               }
               ans = ans | (1 << i);
          }
          else if(bit1 > 0 && bit2 == 0){
               if(carry == 1)
                    continue;
               ans = ans | (1 << i);
          }
          else if(bit1 == 0 && bit2 == 0){
               if(carry == 1){
                    ans = ans | (1 << i);
               }
               carry = 0;
          }
     }
     
     return ans;
}

int main(){
     int a,b;
     cin >> a >> b;
     std::cout << a+b << '\n';
     std::cout << add(a,b) << '\n';
}
