/*
     given boolean expression find how many ways we can form expression to make in
     true or false
*/

#include<iostream>
#include<string>
using namespace std;

int ways(string arr, bool result){
     if(arr.size() == 0)
          return 0;

     if(arr.size() == 1){
          int ans = 0;
          if(result)
               ans =  (arr[0] == '1' || arr[0] == '0');
          //std::cout << "array : " << arr << " " << ans << '\n';
          return ans;
     }

     int count = 0;

     for(int i = 1; i < arr.size(); i += 2){
          char c = arr[i];
          string left = arr.substr(0,i);
          string right = arr.substr(i+1, arr.size());

          int leftTrue = ways(left,true);
          int leftFalse = ways(left,false);
          int rightTrue = ways(right,true);
          int rightFalse = ways(right,false);

          int total = (leftTrue+leftFalse) * (rightTrue+rightFalse);

          int smallOutput = 0;
          if(c == '^')
               smallOutput = leftTrue*rightFalse + leftFalse*rightTrue;

          else if(c == '&')
               smallOutput = leftTrue*rightTrue;

          else
               smallOutput = leftTrue*rightTrue + leftFalse*rightTrue + leftTrue*rightFalse;

          int ans = result ? smallOutput : total - smallOutput;
          count += ans;
          //std::cout << "count till now " << count << " " << ans << '\n';
     }
     return count;
}

int waysDP(string arr, bool result){
     return 0;
}

int main(){
     string str;
     cin >> str;
     bool result = false;
     std::cout << ways(str,result) << '\n';
}
// 0&0&0&1^1|0
// 1^0|0|1
