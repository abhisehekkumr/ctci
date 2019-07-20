/*
implement an algorithm to determine if a string has all distinct characters or not
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;


// using O(n) space to count the frequency of characters in arr
bool isDistinct(string arr){

     if(arr.size() == 1 || arr.size() == 0)
          return true;

     if(arr.size() > 52)
          return false;
     int *count = new int[26];
     for(int i = 0; i < 26; i++)
          count[i] = 0;

     for(int i = 0; i < arr.size(); i++)
          count[arr[i]-'a']++;

     for(int i = 0; i < 26; i++)
     if(count[i] > 1)
          return false;
     return true;
}

// same as above function  but uses character array
// but still it is O(n) space and time complexity
bool isDistinct(char *arr){
     if(arr[0] == '\0')
          return true;

     int *count = new int[26];
     for(int i = 0; i < 26; i++)
          count[i] = 0;

     for(int i = 0; arr[i] != '\0'; i++)
          count[arr[i]-'a']++;

     for(int i = 0; i < 26; i++)
          if(count[i] > 1)
               return false;
     return true;
}

// using sorting string
// but still it is O(n long n) space and time complexity
bool isDistinct_sorting(string arr){
     if(arr.size() == 0 || arr.size() == 1)
          return true;
     sort(arr.begin(), arr.end());
     for(int i = 1; i < arr.size(); i++)
          if(arr[i] == arr[i-1])
               return false;
     return true;
}

// using sorting char array
// but still it is O(n long n) space and time complexity
bool isDistinct_sorting(char *arr){
     if(arr[0] == '\0')
          return true;

     int length = strlen(arr);
     sort(arr,arr+length);
     for(int i = 1; i < length; i++){
          if(arr[i] == arr[i-1])
               return false;
     }
     return true;
}

// the best algorithm fot cheking for qnique characters in array using bit masking
// O(n) time complexity and O(1) space complexity
// only for small character
bool bitmasking(string arr){
     if(arr.size() == 0 || arr.size() == 1)
          return true;
     int bits = 0;
     for(int i = 0; i < arr.size(); i++){
          int index = arr[i] - 'a';
          if(bits & (1 << index))
               return false;
          bits = bits | (1 << index);
     }
     return true;
}

int main(){
     string str;
     cin >> str;
     char c;
     cin >> c;
     char arr[100];
     cin.getline(arr,100);
     std::cout << "O(n) count frequency using string : " << isDistinct(str) << '\n';
     std::cout << "O(n) count frequency using char   : " << isDistinct(arr) << '\n';
     std::cout << "O(n log n) using sort char array : " << isDistinct_sorting(arr) << '\n';
     std::cout << "O(n log n) using sort string : " << isDistinct_sorting(str) << '\n';
     std::cout << "best solution : " << bitmasking(str) << '\n';
     return 0;
}
