/*
     given two arrays find pair of element one each array that if you swap will
     make sum of two arrays equal
*/

#include<iostream>
#include<cmath>
#include<algorithm>
#include<unordered_map>
using namespace std;

int arraySum(int arr[], int n){
     int sum = 0;
     for(int i = 0; i < n; i++)
          sum += arr[i];
     return sum;
}

// time complexity is O(n*m) but space is constant
void findPairs(int arr1[], int arr2[], int n, int m){
     int sum1 = arraySum(arr1,n);
     int sum2 = arraySum(arr2,m);

     if(sum1 == sum2){
          std::cout << -1 << '\n';
          return;
     }

     // we are adding a which is taken from A to B and we are adding b taken
     // from B to A, thus we can basically performing
     // sumA - a + b == sumB - b + a
     // a - b == (sumA - sumB)/2
     // thus pair to exist diff must be negative

     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
               int sumA = sum1 - arr1[i] + arr2[j];
               int sumB = sum2 + arr1[i] - arr2[j];
               if(sumA == sumB){
                    std::cout << arr1[i] << " " << arr2[j] << '\n';
                    //std::cout << sumA << " " << sumB << '\n';
                    return;
               }
          }
     }
     std::cout << "-1" << '\n';
}

// O(n log n + m log m) approach
void findPairsSorting(int arr1[], int arr2[], int n, int m){
     sort(arr1,arr1+n);
     sort(arr2,arr2+m);

     int sumA = arraySum(arr1,n);
     int sumB = arraySum(arr2,m);

     int diff = abs(sumA - sumB);

     if(diff == 0){
          std::cout << -1 << '\n';
          return;
     }

     int i = 0;
     int j = 0;
     while(i < n && j < m){

          int d = abs(2*arr1[i] - 2*arr2[j]);
          if(d == diff){
               std::cout << arr1[i] << " " << arr2[j] << '\n';
               return;
          }

          if(i + 1 == n)
               j++;

          else if(j + 1 == m)
               i++;
          else if(d < diff){
               if(arr1[i] > arr2[j])
                    i++;
               else
                    j++;
          }
          else{
               if(arr1[i] < arr2[j])
                    i++;
               else
                    j++;
          }
     }
     std::cout << -1 << '\n';
}

// O(n + m) time and space complexity
void mostOptimal(int arr1[], int arr2[], int n, int m){
     int sumA = arraySum(arr1,n);
     int sumB = arraySum(arr2,m);

     if(sumA == sumB){
          std::cout << -1 << '\n';
          return;
     }

     unordered_map<int,bool> map;
     for(int i = 0; i < m; i++)
          map[2*arr2[i]] = true;

     for(int i = 0; i < n; i++){
          int result = sumB - sumA + 2*arr1[i];
          if(map.count(result)){
               std::cout << arr1[i] << " " << result/2 << '\n';
               return;
          }
     }
     std::cout << -1 << '\n';
}
int main(){
     int n,m;
     cin >> n >> m;

     int arr1[n],arr2[m];
     for(int i = 0; i < n; i++)
          cin >> arr1[i];
     for(int i = 0; i < m; i++)
          cin >> arr2[i];
     findPairs(arr1,arr2,n,m);
     findPairsSorting(arr1,arr2,n,m);
     mostOptimal(arr1,arr2,n,m);
}
