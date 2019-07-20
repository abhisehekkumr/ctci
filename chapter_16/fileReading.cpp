/*
     given numbers form keypad print all possible valid english words
*/
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

int main(){
     vector<string> v;
     ifstream infile("dictionay.txt");
     string str;
     while(infile >> str)
          v.push_back(str);

     std::cout << v.size() << '\n';
}
