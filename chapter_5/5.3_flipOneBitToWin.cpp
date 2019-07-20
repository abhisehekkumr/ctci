/*
     given one integer number print the maximum length that we can get of consecutive
     onees buy fliping one bit
*/

#include<iostream>
using namespace std;

string printBinaryRepresentation(int n){
     string ans = "";
     while(n){
          ans = (char) ((n & 1) + '0') + ans;
          n = n >> 1;
     }
     std::cout << ans << '\n';
     return ans;
}

// worst case solution O(n*n) time complexity where n is the size of string
int maxOnesLengthWorst(int number){
     string binary = printBinaryRepresentation(number);
     int max = 0;
     bool flag = true;
     for(int i = 0; i < binary.size(); i++){
          if(binary[i] == '0'){
               flag = false;
               int leftCount = 0;
               int rightCount = 0;

               for(int j = i-1; j >= 0; j--){
                    if(binary[j] == '0')
                         break;
                    leftCount += 1;
               }

               for(int j = i+1; j < binary.size(); j++){
                    if(binary[j] == '0')
                         break;
                    rightCount += 1;
               }

               max = max > (leftCount + rightCount + 1) ? max : (leftCount + rightCount + 1);
          }
     }

     if(flag)
          return binary.size();
     return max;
}


// optimal case O(n) time complexity and O(n) space complexity
int maxOnesLengthOptimal(int number){
     string binary = printBinaryRepresentation(number);
     int left[binary.size()];
     int right[binary.size()];

     int count = 0;
     for(int i = 0; i < binary.size(); i++){
          if(binary[i] == '0'){
               left[i] = count;
               count = 0;
          }
          else{
               count += 1;
               left[i] = count;
          }
     }

     count = 0;
     for(int i = binary.size()-1; i >= 0; i--){
          if(binary[i] == '0'){
               right[i] = count;
               count = 0;
          }
          else{
               count += 1;
               right[i] = count;
          }
     }

     int max = 0;
     for(int i = 0; i < binary.size(); i++){
          if(binary[i] == '0'){
               int count = left[i] + right[i] + 1;
               max = max > count ? max : count;
          }
     }
     max = max > left[binary.size()-1] ? max : left[binary.size()-1];
     max = max > right[0] ? max : right[0];
     return max;
}


// most optimal approach O(n) time complexity and O(1) space complexity
int maxOnesLengthMostOptimal(int number){
     string binary = printBinaryRepresentation(number);
     if(~number == 0)
          return binary.size();

     int max = 1;
     int curLenght = 0;
     int prevLength = 0;

     while(number){
          if(number & 1)
               curLenght += 1;
          else{
               prevLength = number & 2 == 0 ? 0 : curLenght;
               curLenght = 0;
          }
          max = max > prevLength + curLenght+1 ? max : prevLength + curLenght+1;
          number = number >> 1;
     }
     return max;
}

int main(){
     int number;
     cin >> number;
     std::cout << maxOnesLengthWorst(number) << '\n';
     std::cout << maxOnesLengthOptimal(number) << '\n';
     std::cout << maxOnesLengthMostOptimal(number) << '\n';
}
