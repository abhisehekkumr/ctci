/*
     check if given string is rotate of another string
*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

// good solution but O(N) space complexity
bool isSubstringFrequency(string str1, string str2){
     if(str1.size() != str2.size())
          return false;
     int count1[26];
     int count2[26];
     for(int i = 0; i < 26; i++){
          count1[i] = 0;
          count2[i] = 0;
     }
     for(int i = 0; i < str1.size(); i++)
          count1[str1[i] - 'a']++;
     for(int i = 0; i < str2.size(); i++)
          count2[str2[i]-'a']++;
     for(int i = 0; i < 26; i++){
          if(count1[i] != count2[i])
               return false;
     }
     return true;
}

// better then above solution but still O(26) space complexity
bool isSubstringFrequencyBetter(string str1, string str2){
     if(str1.size() != str2.size())
          return false;

     int count[26];
     for(int i = 0; i < 26; i++){
          count[i] = 0;
     }

     for(int i = 0; i < str1.size(); i++){
          count[str1[i]-'a']++;
          count[str2[i]-'a']--;
     }

     for(int i = 0; i < 26; i++){
          if(count[i] != 0)
               return false;
     }
     return true;
}

// O(n log n)
bool sorting(string str1, string str2){
     if(str1.size() != str2.size())
          return false;
     sort(str1.begin(), str1.end());
     sort(str2.begin(), str2.end());
     return str1 == str2;
}

// most optimal using bit vector, as we can have capital and small alphabest
// we have to use long for bit vector
bool optimal(string str1, string str2){
     long ans = 0;
     if(str1.size() != str2.size())
          return false;

     for(int i = 0; i < str1.size(); i++){
          ans = ans ^ (1 << (str1[i]-'A'));
          ans = ans ^ (1 << (str2[i]-'A'));
     }
     return ans == 0;
}

int main(){
     string str1;
     string str2;
     cin >> str1;
     cin >> str2;
     std::cout << optimal(str1,str2) << '\n';
}
