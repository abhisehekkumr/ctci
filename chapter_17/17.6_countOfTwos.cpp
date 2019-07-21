/*
     given number n find the total number of 2's from 0 to n
*/

#include<iostream>
#include<cmath>
using namespace std;

bool hasTwo(int n){
     while(n){
          int d = n%10;
          if(d == 2)
               return true;
          n = n/10;
     }
     return false;
}

// time complexity is O(n * d) where n is maximum number and d is total number of
// digits in it
void printNumbers(int n){
     int count = 0;
     for(int i = 2; i <= n; i++){
          if(hasTwo(i))
               count += 1;
     }
     std::cout << count << '\n';
}

int countInTen(int n){
     while(n){
          int d = n%10;
          if(d == 3)
               return 10;
          n = n / 10;
     }
     return 1;
}

// works for some test cases but mostly wrong
void printNumbersOptimal(int n){
     int count = 1;
     if(n < 10){
          std::cout << 1 << '\n';
          return;
     }

     for(int i = 10; i <= n; i += 10){
          count += countInTen(i);
     }
     std::cout << count << '\n';
}

int mostOptimal(int n){
     if(n < 2)
          return 0;
     int count = 0;
     int power10 = 1;

     while(power10*10 < n)
          power10 *= 10;

     int msb = n/power10;
     int remainder = n%power10;
     if(msb > 2)
          count += power10;
     if(msb == 2)
          count += remainder + 1;
     count += msb*mostOptimal(power10);
     count += mostOptimal(remainder);
     return count;
}

int main(){
     int n;
     cin >> n;
     printNumbers(n);
     //printNumbersOptimal(n);
     std::cout << mostOptimal(n) << '\n';
}
