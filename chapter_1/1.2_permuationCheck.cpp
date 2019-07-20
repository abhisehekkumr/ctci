/*
given two string and check if two string are permuation of each other
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
it will hit the base case for exactly n! times where n is size of string
and the for loop will call the permuation function n time thus out
time complexity becomes O(n*n!)

and in order to compare two string we have to compre two strings which takes O(n)
time thus out total time complexity is

O(n*n*n!)
*/
bool isPermuation(string arr, string ans, int j = 0){
     if(j+1 == arr.size()){
          if(arr == ans)
               return true;
          return false;
     }

     for(int i = j; i < arr.size(); i++){
          char c = arr[i];
          arr[i] = arr[j];
          arr[j] = c;
          if(isPermuation(arr,ans,j+1))
               return true;
          c = arr[i];
          arr[i] = arr[j];
          arr[j] = c;
     }
     return false;
}

// below function has O(n) space complexity and (n log n) time complexity
bool isPermuation_sorting(string patter1, string patter2){
     if(patter1.size() != patter2.size())
          return false;

     sort(patter1.begin(), patter1.end());
     sort(patter2.begin(), patter2.end());

     for(int i = 0; patter1[i] != '\0'; i++)
          if(patter1[i] != patter2[i])
               return false;
     return true;
}

// it has O(n) space complexity and O(n) time complexity
bool  isPermuation_frequency(string pattern1, string pattern2){
     if(pattern1.size() != pattern2.size())
          return false;

     int *count = new int[26];
     for(int i = 0; i < 26; i++)
          count[i] = 0;

     for(int i = 0; pattern1[i] != '\0'; i++){
          count[pattern1[i]-'a']++;
          count[pattern2[i]-'a']--;
     }

     for(int i = 0; i < 26; i++)
          if(count[i] != 0)
               return false;
     return true;
}

int main(){
     string arr1;
     string arr2;
     cin >> arr1;
     cin >> arr2;
     std::cout << "using sorting O(n log n) : " << isPermuation_sorting(arr1,arr2) << '\n';
     std::cout << "using counting O(n) : " << isPermuation_frequency(arr1,arr2) << '\n';
     std::cout << "using permuation O(n*n*n!) : " << isPermuation(arr1,arr2) << '\n';
}
