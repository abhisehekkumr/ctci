/*
     given double number print its binary representation, if number cannot be
     represented in 32 bits than return 0
*/
#include<iostream>
using namespace std;

int *binaryRepresentation(double number){
     int *arr = new int[32];
     for(int i = 0; i < 32; i++)
          arr[i] = -1;

     for(int i = 0; i < 32; i++){
          int bit = number*2;
          std::cout << bit;
          arr[i] = bit;
          number = number*2 - bit;

          if(number == 0)
               break;
     }

     std::cout << '\n';
     if(number == 0)
          return arr;
     std::cout << "error" << '\n';
     return NULL;
}

int main(){
     double number;
     cin >> number;
     int *arr = binaryRepresentation(number);
     if(!arr)
          return 0;
     for(int i = 0; i < 32; i++){
          if(arr[i] == -1)
               break;
          std::cout << arr[i];
     }
     std::cout << '\n';
     delete [] arr;
}
