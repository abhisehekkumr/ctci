/*
     given two numbers n and m, fit m into n, from j to i location in n
*/

#include<iostream>
using namespace std;

int insertion(int n, int m, int j, int i){
     int allones = ~0;
     int left = allones << (j+1);
     int right = (1 << i)-1;
     int mask = left | right;

     n = n & mask;
     return n | m << i;
}

int main(){
     int n;
     cin >> n;
     int m;
     cin >> m;
     int i,j;
     cin >> j >> i;
     std::cout << insertion(n,m,j,i) << '\n';
     int k = 1;
}
