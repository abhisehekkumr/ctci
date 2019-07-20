/*
     given two integers apply addition, subtration, multiply and division
*/

#include<iostream>
using namespace std;

int minusOperation(int a, int b){
     b = (~b)+1;
     return a+b;
}

int multiply(int a, int b){
     int ans = 0;
     bool flag = false;
     if(b < 0){
          b = (~b)+1;
          flag = true;
     }
     while(b--)
          ans += a;
     if(flag)
          ans = (~ans) + 1;
     return ans;
}

int division(int a, int b){
     bool flag = false;
     if(a < 0 && b < 0){
          a = (~a)+1;
          b = (~b)+1;
     }
     else if(a < 0){
          a = (~a)+1;
          flag = true;
     }
     else if(b < 0){
          b = (~b)+1;
          flag = true;
     }

     int count = 0;
     while(a > 0){
          a = minusOperation(a,b);
          if(a < 0)
               continue;
          count += 1;
     }

     if(flag)
          count = (~count)+1;
     return count;
}

int main(){
     int a,b;
     cin >> a >> b;
     std::cout << "addition :" << a+b << '\n';
     std::cout << "minus : "  << minusOperation(a,b)<< '\n';
     std::cout << "multiply : " << multiply(a,b) << '\n';
     std::cout << "division : " << division(a,b) << '\n';
}
