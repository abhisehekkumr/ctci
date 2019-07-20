/*
     given array of sorted string with maximum number of "" placed randomly
     search for given string
*/

#include<iostream>
using namespace std;

bool isBigger(string str1, string value){

     for(int i = 0; i < min(str1.size(), value.size()); i++){
          if(str1[i] > value[i])
               return false;
          if(str1[i] < value[i])
               return true;
     }

     if(value.size() > str1.size())
          return false;
     return true;
}

// best approach for binary seach although in worst case it will turn into O(n)
// but in fact in is not O(n), if look at carefully we are comparing strngs which
// takes O(l) time where time is length of strings
// thus overall complexity of algorithm is O(n*l) in worsr case
// in average case O(l log n)
bool binarySearch(string arr[], string value, int start, int end){

     if(start > end)
          return false;

     int mid = (start + end)/2;
     if(arr[mid] == value)
          return true;

     int left = mid-1;
     int right = mid+1;

     bool flag = false;

     if(arr[mid].size() == 0)
          flag = true;

     while(flag){

          if(left >= start && arr[left].size() != 0){
               mid = left;
               break;
          }

          if(right <= end && arr[right].size() != 0){
               mid = right;
               break;
          }

          if(left < 0 && right > end)
               return false;

          left--;
          right++;
     }

     if(arr[mid] == value)
          return true;

     if(isBigger(arr[mid],value))
          return binarySearch(arr,value,mid+1,end);
     return binarySearch(arr,value,start,mid-1);
}

bool patheticSearch(string arr[], string value, int n){
     for(int i = 0; i < n; i++){
          if(arr[i] == value)
               return true;
     }
     return false;
}

int main(){
     string arr[] = {"at","","","","ball","","","car","","","dad","",""};
     int n = 13;
     string value = "dad";
     std::cout << binarySearch(arr,value,0,n-1) << '\n';
     std::cout << patheticSearch(arr,value,n) << '\n';
}
