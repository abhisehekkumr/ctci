/*
     given array of strings sort in such a way that anagram will be next to
     each other
*/

#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;

bool isAnagram(string arr1, string arr2){
     if(arr1.size() != arr2.size())
          return false;

     int first = 0;
     for(int i = 0; i < arr1.size(); i++){
          first = first^(1 << (arr1[i]-'a'));
          first = first^(1 << (arr2[i]-'a'));
     }
     return first == 0;
}

void merge(string arr[], int low, int mid, int end){
     int n1 = mid - low + 1;
     int n2 = end - mid;

     string arr1[n1], arr2[n1];

     for(int i = 0; i < n1; i++)
          arr1[i] = arr[low + i];
     for(int i = 0; i < n2; i++)
          arr2[i] = arr[mid + 1 + i];

     int i = 0;
     int j = 0;
     int k = low;

     while(i < n1 && j < n2){
          if(isAnagram(arr1[i],arr2[j]))
               arr[k++] = arr1[i++];
          else
               arr[k++] = arr2[j++];
     }

     while(i < n1)
          arr[k++] = arr1[i++];

     while(j < n2)
          arr[k++] = arr2[j++];
}

void mergeSort(string arr[], int low, int high){
     if(low < high){
          int mid = (low + high)/2;
          mergeSort(arr,low,mid);
          mergeSort(arr,mid+1,high);
          merge(arr,low,mid,high);
     }
}

void sortAnagrams(string arr[], int n){

     for(int i = 0; i < n; i++){
          for(int j = i+1; j < n; j++){
               if(isAnagram(arr[i], arr[j])){
                    string a = arr[i+1];
                    arr[i+1] = arr[j];
                    arr[j] = a;
                    i++;
               }
          }
     }
}

void sortUsingHashMap(string arr[], int n){

     unordered_map<string, vector<string>> m;
     string keys[n];
     int j = 0;
     for(int i = 0; i < n; i++){
          string ans = arr[i];
          sort(ans.begin(), ans.end());
          m[ans].push_back(arr[i]);
          keys[j] = ans;
          j++;
     }

     int k = 0;
     unordered_map<string, vector<string>> :: iterator it;
     for(int i = 0; i < n; i++){
          if(m.count(keys[i])){
               for(int j = 0; j < m[keys[i]].size(); j++)
                    arr[k++] = m[keys[i]].at(j);
               m.erase(keys[i]);
          }
     }9


     std::cout << "after hash map" << '\n';
     for(int i = 0; i < n; i++)
          std::cout << arr[i] << '\n';
}

int main(){
     int n;
     cin >> n;

     string arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     //mergeSort(arr,0,n-1);
     sortAnagrams(arr,n);
     //sort(arr,arr+n,isAnagram);
     std::cout << "after sorting" << '\n';
     for(int i = 0; i < n; i++)
          std::cout << arr[i] << '\n';
     sortUsingHashMap(arr,n);
}

/*
9
abc
fgh
jklm
bca
jkl
ghf
mno
cba
hgf


*/
