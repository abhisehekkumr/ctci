#include<iostream>
using namespace std;
#define mod 1000000007

long long sum = 0;

void helper(long long arr[], int size, long long ans = 0){

    if(size == 0){
        if(ans == 0)
            return;
        sum = ((ans % mod) + sum) % mod;
        return;
    }
    //cout << size << " first" << endl;
    helper(arr+1,size-1,ans);
    //cout << size << " second" << endl;
    helper(arr+1,size-1,ans + arr[0]);
}

int power(int n){
     int res = 1;
     int base = 2;

     while(n){
          if(n & 1)
               res = base*res;
          base = base*base;
          n = n >> 1;
     }
     return res;
}

int SquareSum(int arr[], int n){
     int total = power(n)/2;
     //std::cout << total << '\n';
     int sum = 0;
     for(int i = 0; i < n; i++)
          sum += arr[i]*arr[i]*total;
     return sum;
}

int main(){
/*     int n;
     cin >> n;

     long long arr[n];
     for(int i = 0; i < n; i++){
          cin >> arr[i];
          arr[i] = arr[i]*arr[i];
     }
     helper(arr,n);
     int ans = sum%mod;
     std::cout << ans << '\n';
     */

     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     std::cout << SquareSum(arr,n) << '\n';
}
