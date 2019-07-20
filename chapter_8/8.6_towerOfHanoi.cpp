/*
     implement tower of hanoi
*/

#include<iostream>
using namespace std;

void towerOfHanoi(int n, char from, char to, char aux){
     if(n == 1){
          //std::cout << "this is printing" << '\n';
          std::cout << from << " to " << to << '\n';
          return;
     }
     towerOfHanoi(n-1,from,aux,to);
     std::cout << from << " to " << to << '\n';
     towerOfHanoi(n-1,aux,to,from);
}

int main(){
     int n;
     cin >> n;
     towerOfHanoi(n,'A','B','C');
}
