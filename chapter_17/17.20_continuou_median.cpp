/*
     find the midian of array as its elememt are comming
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void printMedians(int arr[], int n){
     priority_queue<int> max;
     priority_queue<int,vector<int>,greater<int>> min;

     for(int i = 0; i < n; i++){
          if(max.size() == 0 && min.size() == 0){
               max.push(arr[i]);
          }
          else if(max.top() >= arr[i]){
               //std::cout << "max heap : " << arr[i] << " " << max.top() << '\n';
               max.push(arr[i]);
          }
          else{
               //std::cout << "min heap : " << arr[i] << '\n';
               min.push(arr[i]);
          }

          //std::cout << "max heap data" << " " << max.top() << '\n';

          if(max.size() > min.size() + 1){
               int top = max.top();
               max.pop();
               min.push(top);
          }

          if(max.size() + 1 < min.size()){
               int top = min.top();
               min.pop();
               max.push(top);
          }

          if(min.size() == max.size())
               std::cout << (max.top() + min.top())/2 << ' ';
          else if(min.size() > max.size())
               std::cout << min.top() << ' ';
          else
               std::cout << max.top() << ' ';
     }
     std::cout << '\n';
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     printMedians(arr,n);
}
