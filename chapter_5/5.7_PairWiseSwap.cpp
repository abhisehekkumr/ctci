/*
     given number swap its bits pair wise with minumum instructions possible
*/
#include<iostream>
using namespace std;

// this is good approach but it is not what question desired
// constant space and time complexity
int pairWiseSwap(int number){
     for(int i = 0; i < 32; i += 2){
          int bit1 = number & (1 << i);
          int bit2 = number & (1 << (i+1));

          if(bit1 == 0){
               number = number & ~(1 << (i+1));
          }
          else{
               number = number | (1 << (i+1));
          }

          if(bit2 == 0){
               number = number & ~(1 << i);
          }

          else{
               number = number | (1 << i);
          }
     }
     return number;
}

// fucking best approach
// 0xAAAAAAAA has all ones at even place thus (number & 0xAAAAAAAA) will all ones
// at odd place and if we shift 0xAAAAAAAA 1 bit left then taking and then we
// can get all the ones at odd,then shift even to left and odd to right by 1 bit
// and mertge them then return final result
int pairWiseSwapOptimal(int number){
     return ((number & (0xAAAAAAAA)) >> 1) | (((0xAAAAAAAA >> 1) & number) << 1);
}

int main(){
     int number;
     cin >> number;
     std::cout << pairWiseSwap(number) << '\n';
     std::cout << pairWiseSwapOptimal(number) << '\n';
}
