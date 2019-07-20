/*
     given string print all its permuatations
*/

#include<iostream>
using namespace std;

void permuatations(string str, int j = 0){

     if(j + 1 == str.size()){
          std::cout << str << '\n';
          return;
     }

     for(int i = j; i < str.size(); i++){
          char c = str[i];
          str[i] = str[j];
          str[j] = c;
          permuatations(str,j+1);
          c = str[i];
          str[i] = str[j];
          str[j] = c;
     }
}

int main(){
     string str;
     cin >> str;
     std::cout << "permuatations" << '\n';
     permuatations(str,0);
}
