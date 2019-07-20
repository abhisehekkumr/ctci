/*
sample program to check total number of bits set in number for diifent numeric data types
*/

#include<iostream>
using namespace std;

int bits(int n){
     int size = sizeof(n)*8;
     int count = 0;
     while(n){
          count += 1;
          n &= n-1;
     }
     return count;
}

int bits(long n){
     int size = sizeof(n)*8;
     int count = 0;
     while(n){
          count += 1;
          n &= n-1;
     }
     return count;
}

int bits(long long n){
     int size = sizeof(n)*8;
     int count = 0;
     while(n){
          count += 1;
          n &= n-1;
     }
     return count;
}

int main(){
     int ni;
     long nl;
     long long nll;
     cin >> ni >> nl >> nll;
     std::cout << bits(ni) << " " << bits(nl) << " " << bits(nll) << '\n';
}
