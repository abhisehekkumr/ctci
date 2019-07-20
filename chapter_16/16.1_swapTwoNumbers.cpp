/*
     given two number swap them without using temporary variables
*/

#include<iostream>
using namespace std;

int main(){
     int a,b;
     cin >> a >> b;

     // swap first method
     a = a ^ b;
     b = a ^ b;
     a = a ^ b;
     std::cout << a << " " << b << '\n';

     // second metnod
     a = a + b;
     b = a - b;
     a = a - b;
     std::cout << a << " " << b << '\n';

     // third mathod
     a = a - b;
     b = a + b;
     a = b - a;
     std::cout << a << " " << b
      << '\n';
}
