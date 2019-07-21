/*
     given two numbers add them without using any arithmetic operator
*/

#include<iostream>
using namespace std;

// xor has a property that if two ones are xored than result will be 0 as in
// addition of two numbers, thus if xor two number we will get sum without carry
// but as in half adder carry can be traced by and operator, because carry can
// only be genrated by two 1' or previous one. thus we have to keep shifting carry
// so that we can pass carry as submission progress

int sum(int a, int b){
     if(b == 0)
          return a;
     int add = a ^ b;
     int carry = (a&b) << 1;
     return sum(add,carry);
}

int main(){
     int a,b;
     cin >> a >> b;
     std::cout << sum(a,b) << '\n';
}
