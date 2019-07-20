/*
     given string as pattern and value where pattern can have only values a,b.
     find if that pattern can be found in value

     pattern : aabab
     value : catcatgocatgo
     output: true
*/

#include<iostream>
#include<string>
using namespace std;

string buildPattern(string a,string b, string pattern){
     //std::cout << "a : " << a << " " << " b :"  << b << '\n';
     string ans = "";
     for(int i = 0; i < pattern.size(); i++){
          if(pattern[i] == 'a')
               ans += a;
          else
               ans += b;
     }
     return ans;
}

// O(n*n*n*n) solution the most pathetic one
bool matchPattern(string value,string pattern){
     for(int i = 0; i < value.size(); i++){
          string a = value.substr(0,i);
          for(int start = i; start < value.size(); start++){
               for(int end = start; end < value.size(); end++){
                    string b = value.substr(start,end);
                    string ans = buildPattern(a,b,pattern);
                    if(ans == value)
                         return true;
               }
          }
     }
     return false;
}

int countOFChar(string pattern,char c){
     int count = 0;
     for(int i = 0; i < pattern.size(); i++){
          if(pattern[i] == c)
               count += 1;
     }
     return count;
}

int firstIndex(string pattern, char c){
     for(int i = 0; i < pattern.size(); i++){
          if(pattern[i] == c)
               return i;
     }
     return pattern.size();
}

string getString(string value, int start, int end){
     string ans = "";
     for(int i = start; i < start + end; i++){
          ans += value[i];
     }
     return ans;
}

// most optimal solution this takes of O(n*n)
bool optimal(string value,string pattern){
     if(pattern.size() == 0)
          return value.size() == 0;

     char mainChar = pattern[0];
     char altChar = pattern[0] == 'a' ? 'b' : 'a';
     int size = value.size();

     int countOfMain = countOFChar(pattern,mainChar);
     int countOfAlt = pattern.size() - countOfMain;
     int firstAlit = firstIndex(pattern, altChar);
     // total size of character that will be consumed by main character
     int maxSize = size/countOfMain;

     for(int mainSize = 0; mainSize <= maxSize; mainSize++){
          string first = value.substr(0,mainSize);
          // based currnet size of mainString what will the remaing size of
          // alternative string
          int remainingLenght = size - mainSize*countOfMain;

          // only valid if we dont have alt character or remaining length can
          // take all the characters of alt character
          if(countOfAlt == 0 || remainingLenght%countOfAlt == 0){
               // juping to the first index of alt character in value string
               // how do we know that we will jump to acurate position is based
               // one the size of main currently and first index of alt char
               // e.x : if first index of alt character is 2, that means there
               // 2 main char brfore alt, thus if size of current main is 5
               // then we have to skip 10 character directly
               int altIndex = firstAlit*mainSize;
               int altSize = countOfAlt == 0 ? 0 : remainingLenght/countOfAlt;
               string second = countOfAlt == 0 ? "": getString(value,altIndex,altSize);

               string ans = buildPattern(first,second,pattern);
               if(ans == value)
                    return true;
          }
     }
     return false;
}

int main(){
     string value,pattern;
     cin >> value >> pattern;
     std::cout << matchPattern(value,pattern) << '\n';
     std::cout << optimal(value,pattern) << '\n';
}

/*
catcatgocatgo aabab
*/
