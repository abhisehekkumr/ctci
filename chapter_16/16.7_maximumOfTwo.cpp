/*
     given two numbers find the maximum of two element without using any condition
     statements like if else and any comparision operator
*/

#include<iostream>
using namespace std;


// find the sign bit is set or not and based on that make another 0
int maxOptimal(int a, int b){
     int m = ((a-b) >> 31);
     int max = (a&(~m)) + ((m)&b);
     return max;
}

int main(){
     int a = 5,b = 7;
     //cin >> a >> b;
     std::cout << maxOptimal(a,b) << '\n';

     int n = 5;
     cin >> n;
     int m = (n & (~(1 << 31)));
     std::cout << m << '\n';
}
