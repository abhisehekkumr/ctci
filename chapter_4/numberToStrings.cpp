/*
     converting number to string
*/
#include<iostream>
#include<sstream>
using namespace std;

string numberToString(long long number){
     ostringstream convert;
     convert << number;
     return convert.str() + "abhishek";
}

int main(){
     long long number;
     cin >> number;
     std::cout << numberToString(number) << '\n';
}
