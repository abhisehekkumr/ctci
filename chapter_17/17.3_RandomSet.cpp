/*
     given array of size n element , find the subset of size m where elements
     are picked from array randomly and their probability of chooosing element
     is same
*/
#include<iostream>
#include<random>
using namespace std;

int RandomNumber(int lower, int upper){
     double number = ((double)(rand())/RAND_MAX)*(upper - lower + 1);
     return (int)(number);
}

int *findSubset(int *arr, int n, int m){
     int *subset = new int[m];
     for(int i = 0; i < m; i++)
          subset[i] = arr[i];
     for(int i = m; i < n; i++){
          int k = RandomNumber(0,i);
          if(k < m)
               subset[k] = arr[i];
     }
     return subset;
}

// much better approach
int *Subset(int arr[], int n, int m){
     int *ans = new int[m];
     for(int i = 0; i < n; i++){
          int k = RandomNumber(0,i);
          if(k < m)
               ans[k] = arr[i];
     }
     return ans;
}
int main(){
     int n;
     cin >> n;

     int arr[n];

     for(int i = 0; i < n; i++)
          cin >> arr[i];
     int m;
     cin >> m;
     int *subset = Subset(arr,n,m);

     for(int i = 0; i < m; i++)
          std::cout << subset[i] << ' ';
     std::cout << '\n';
}
