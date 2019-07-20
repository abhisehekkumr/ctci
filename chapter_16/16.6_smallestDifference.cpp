/*
     given two arrays find the smallest difference between two element where first
     element is in array A and second one is in B
*/

#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

// O(n*n) due to double loops
int smallestDifferent(int *a, int *b, int n, int m){
     int count = INT_MAX;

     for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
               int smallest = a[i] < b[j] ? a[i] : b[j];
               int largest = a[i] > b[j] ? a[i] : b[j];
               count = count < largest-smallest ? count : largest-smallest;

               if(count == 0)
                    return count;
          }
     }
     return count;
}

// O(n log n) due to complexity and O(n) space complexity
int smallestDifferentOptimal(int *a, int *b, int n, int m){
     sort(a,a+n);
     sort(b,b+m);

     int min = INT_MAX;
     int i = 0, j = 0;
     while(i < n && j < m){
          int smallest = a[i] < b[j] ? a[i] : b[j];
          int largest = a[i] > b[j] ? a[i] : b[j];
          min = min < largest-smallest ? min : largest-smallest;

          if(min == 0)
               return min;

          if(a[i] < b[j])
               i++;
          else
               j++;
     }
     return min;
}

int main(){
     int n,m;
     cin >> n >> m;

     int a[n], b[m];
     for(int i = 0; i < n; i++)
          cin >> a[i];
     for(int i = 0; i < m; i++)
          cin >> b[i];
     std::cout << smallestDifferent(a,b,n,m) << '\n';
     std::cout << smallestDifferentOptimal(a,b,n,m) << '\n';
}
