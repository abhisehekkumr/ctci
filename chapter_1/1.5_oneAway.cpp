/*
     given two strings determine wheather they are one distance away or zero
     distace away
*/
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

// O(n) time complexity and O(1) space
int distance(string str1, string str2){
     int n1 = str1.size();
     int n2 = str2.size();
     if(abs(n1-n2) > 1)
          return false;
     int count1[26];
     for(int i = 0; i < 26; i++)
          count1[i] = 0;
     for(int i = 0; i < str1.size(); i++)
          count1[str1[i]-'a']++;
     int total = 0;
     int count2[26];
     for(int i = 0; i < 26; i++)
          count2[i] = 0;
     for(int i = 0; i < str2.size(); i++)
          count2[str2[i]-'a']++;
     for(int i = 0; i < 26; i++)
          if((count1[i] >= 1 && count2[i] == 0) || (count1[i] == 0 && count2[i] >= 1) )
               total += 1;
     if(total > 2)
          return false;
     return true;
}

bool distance_optimal(string str1, string str2){
     int n1 = str1.size();
     int n2 = str2.size();

     if(abs(n1-n2) > 1)
          return false;

     int ans = 0;
     for(int i = 0; i < str1.size(); i++)
          ans = ans ^ (1 << (str1[i]-'a'));

     for(int i = 0; i < str2.size(); i++)
          ans = ans ^ (1 << (str2[i]-'a'));

     int count = 0;

     // count the number of set bits
     while (ans) {
          ans = ans&(ans-1);
          count++;
     }
     return count <= 2;
}

int main(){
     string str1;
     string str2;
     cin >> str1;
     cin >> str2;
     std::cout << distance_optimal(str1,str2) << '\n';
}
