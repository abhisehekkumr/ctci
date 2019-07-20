/*
     given a  integer find the next smaller and larger number that have
     equal number of 1's
*/

#include<iostream>
using namespace std;

int countOnes(int number){
     int count = 0;
     while(number){
          count += 1;
          number = number & (number - 1);
     }
     return count;
}

// time complexity is O(kn) where n is number of 1's in number and k is the
// distance from given number that we are working with
void printNextNumbers(int number){
     int numberCount = countOnes(number);
     int largeCount = 0;
     int smallCount = 0;
     int n = number+1;
     int large = 0;
     int small = 0;
     while(numberCount != largeCount){
          largeCount = countOnes(n);
          large = n;
          n++;
     }
     n = number-1;
     while(numberCount != smallCount){
          smallCount = countOnes(n);
          small = n;
          n--;

          if(n < 0){
               small = -1;
               break;
          }
     }
     std::cout << small << " " << number << " " << large << '\n';
}

string decimalToBinary(int number){
     string ans = "";
     while(number){
          ans = (char)((number & 1) + '0') + ans;
          number = number >> 1;
     }
     return ans;
}

int nextLarge(int number){
     int n = number;
     int c0 = 0;
     int c1 = 0;

     int bit = n & 1;
     while((bit == 0) && n){
          c0++;
          n = n >> 1;
          bit = n & 1;
     }


     bit = n & 1;
     while(bit > 0){
          c1++;
          n = n >> 1;
          bit = n & 1;
     }

     //std::cout << c0 << " " << c1 << " " << n << '\n';

     if(c0 + c1 == 31  || c0 + c1 == 0)
          return -1;

     number = number | (1 << (c0 + c1));
     number = number & ~(1 << (c0 + c1 -1));
     number = number | ((1 << (c1-1))-1);
     return number;
}

int nextSmall(int number){
     int n = number;
     int c0 = 0;
     int c1 = 0;

     int bit = n & 1;
     while(bit > 0 && n){
          c1++;
          n = n >> 1;
          bit = n & 1;
     }

     if(n == 0)
          return -1;

     bit = n & 1;
     while(bit == 0 && n){
          c0++;
          n = n >> 1;
          bit = n & 1;
     }

     n = number;
     int p = c0 + c1;
     n = n & ((~0 << (p + 1)));
     int mask = (1 << (c1 + 1))-1;
     n = n | mask << (c0 -1);
     return n;
}

void printNextNumbersOptimal(int number){

     std::cout << nextLarge(number) << '\n';
     std::cout << nextSmall(number) << '\n';
}

int main(){
     int number;
     cin >> number;
     printNextNumbers(number);
     printNextNumbersOptimal(number);
}
