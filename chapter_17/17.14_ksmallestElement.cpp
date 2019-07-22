/*
     given array return kth smallest element
*/

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int kthSmallestElementSort(int arr[], int n, int k){
     sort(arr,arr+n);
     if(k >= n)
          return arr[n-1];
     return arr[k-1];
}

int kthSmallestElementQeue(int arr[], int n, int k){
     priority_queue<int> q;
     //std::cout << "created" << '\n';
     for(int i = 0; i < k; i++)
          q.push(arr[i]);
     for(int i = k; i < n; i++){
          if(q.empty()){
               q.push(arr[i]);
               continue;
          }
          //std::cout << q.top() << '\n';
          if(!q.empty() && q.top() > arr[i]){
               q.pop();
               q.push(arr[i]);
          }
     }
     return q.top();
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     int k;
     cin >> k;

     std::cout << kthSmallestElementSort(arr,n,k) << '\n';
     std::cout << kthSmallestElementQeue(arr,n,k) << '\n';
}


/*
10
0 9 8 7 6 5 4 3 2 1
5
*/
