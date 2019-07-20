/*
     determine number of bits to flip to convert one integerto another
*/

#include<iostream>
using namespace std;

// constant approach
int bitsToFlip(int a, int b){
     int count = 0;

     for(int i = 0; i < 32; i++){
          int bit1 = a & (1 << i);
          int bit2 = b & (1 << i);

          if(bit1 != bit2)
               count += 1;
     }
     return count;
}

// better approach
int bitsToFlipXor(int a, int b){
     int c = a ^ b;
     int count = 0;
     while(c){
          count += 1;
          c = c & (c - 1);
     }
     return count;
}

int main(){
     int a,b;
     cin >> a >> b;
     std::cout << bitsToFlip(a,b) << '\n';
     std::cout << bitsToFlipXor(a,b) << '\n';
}
