/*
     given two string determine if one is permutaion of other
*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

// using sorting O(n log n)
bool isPermutation(string palindrome, string permutaion){
     if(palindrome.size() != permutaion.size())
          return false;
     sort(palindrome.begin(), palindrome.end());
     sort(permutaion.begin(), permutaion.end());

     for(int i = 0; i < palindrome.size(); i++)
          if(palindrome[i] != permutaion[i])
               return false;
     return true;
}

// O(n) time complexity, although we are using array size 26 but it is constant number
// so space somplexity is O(n)
bool isPermutation(string palindrome){
     if(palindrome.size() == 0 || palindrome.size() == 1)
          return true;
     int count[26];
     for(int i = 0; i < 26; i++)
          count[i] = 0;
     for(int i = 0; i < palindrome.size(); i++)
          count[palindrome[i]-'a']++;
     int odd = 0;
     for(int i = 0; i < 26; i++)
          if(count[i]%2 == 1)
               odd += 1;
     return odd <= 1;
}

// merging count and finding odd into single for loop
bool isPermutation_merge(string palindrome){
     if(palindrome.size() == 0 || palindrome.size() == 1)
          return true;
     int count[26];
     for(int i = 0; i < 26; i++)
          count[i] = 0;
     int odd = 0;
     for(int i = 0; i < palindrome.size(); i++){
          count[palindrome[i]-'a']++;
          if(count[palindrome[i]-'a']%2 == 1)
               odd++;
          else
               odd--;
     }
     return odd <= 1;
}

// O(n) time complexity and O(1) space complexity but more optimal approach
bool isPermuation_bitmaking(string palindrome){
     if(palindrome.size() == 0 || palindrome.size() == 1)
          return true;
     int isPalindrome = 0;
     for(int i = 0; i < palindrome.size(); i++){
          int index = palindrome[i]-'a';
          isPalindrome = isPalindrome ^ (1 << index);
     }
     if(isPalindrome == 0)
          return true;
     int count = 0;
     for(int i = 0; i < 32; i++)
          if((isPalindrome & (1 << i)) == i)
               count += 1;
     return count == 1;
}

// best approach
bool isPermuation_optimal(string palindrome){
     if(palindrome.size() == 0 || palindrome.size() == 1)
          return true;
     int isPalindrome = 0;
     for(int i = 0; i < palindrome.size(); i++){
          int index = palindrome[i]-'a';
          isPalindrome = isPalindrome ^ (1 << index);
     }
     if(isPalindrome == 0)
          return true;
     int verify = isPalindrome - 1;
     return (verify & isPalindrome) == 0;
}

int main(){
     string palindrome;
     cin >> palindrome;
     std::cout << isPermuation_optimal(palindrome) << '\n';
}
