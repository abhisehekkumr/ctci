/*
     given n, find the trailing zeros of its factorial
*/
#include<iostream>
using namespace std;

int TrailingZeros(int n){
     int c = 5;
     int count = 0;
     while(c <= n){
          count += n/c;
          c = c*5;
     }
     return count;
}

int main(){
     int n;
     cin >> n;
     std::cout << TrailingZeros(n) << '\n';
}
