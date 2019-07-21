/*
     find the longest common subsequence where hight should be larger and weight should be high
     at the bottom of circus tower
*/

#include<iostream>
#include<algorithm>
using namespace std;

struct Person {
     int height;
     int weight;
};

// this is O(n*n) solution
int longestSequence(Person arr[], int n){
     int count[n];
     count[0] = 1;

     for(int i = 1; i < n; i++){
          count[i] = 1;
          for(int j = i-1; j >= 0; j--){
               if(arr[i].weight <= arr[j].weight)
                    continue;
               int ans = count[j]+1;
               if(ans > count[i])
                    count[i] = ans;
          }
     }

     int max = 0;
     for(int i = 0; i < n; i++){
          if(count[i] > max)
               max = count[i];
     }
     return max;
}

bool compare(Person p1, Person p2){
     return p1.height < p2.height;
}

int main(){
     int n;
     cin >> n;

     Person arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i].height >> arr[i].weight;
     sort(arr,arr+n,compare);
     std::cout << longestSequence(arr,n) << '\n';
}
