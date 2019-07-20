/*
     given array find two indecies such that if we sort element in that range
     then we will have sorted array
*/

#include<iostream>
#include<algorithm>
using namespace std;

bool isSorted(int arr[],int n){
     if(n == 0)
          return true;
     if(n == 1)
          return true;
     bool result = isSorted(arr+1,n-1);
     return result && (arr[0] < arr[1]);
}

void print(int arr[], int i, int j){

     for(int k = i; k <= j; k++)
          std::cout << arr[k] << ' ';
     std::cout << '\n';
}

// this is O(n*n*n) solution one of the worst way to solve problem like this
int minimumDistance(int arr[], int n){
     int aux[n];

     int minCount = 99999999;

     for(int i = 0; i < n; i++){

          for(int k = 0; k < n; k++)
               aux[k] = arr[k];

          for(int j = i+1; j < n; j++){
               if(aux[j-1] > aux[j]){
                    sort(aux+i,aux+j+1);
                    //std::cout << "indices : " << i << " " << j << '\n';
                    //print(aux,0,n-1);
                    if(isSorted(aux,n))
                         minCount = minCount < (j-i) ? minCount : (j-i);
               }
               //minCount = minCount < (j-i) ? minCount : (j-i);
          }
     }

     if(minCount == 99999999)
          return 0;
     return minCount;
}


// better than above but still worst one
// its time complexity is O(n*n log n)
int littleBetter(int arr[], int n){
     int minCount = 0;
     int min = 0, max = 0;

     for(int i = 0; i < n-1; i++){
          if(arr[i] > arr[i+1]){
               min = i;
               break;
          }
     }

     for(int i = n - 2; i > 1; i--){
          if(arr[i] > arr[i+1]){
               max = i;
               break;
          }
     }
     //std::cout << min << " " << max << " result " << '\n';
     int i = min, j = max;
     int count = 0;
     while(i >= 0 || j < n){

          // both sides
          if(i >= 0 && j < n){
               sort(arr+i,arr+j+1);
               if(isSorted(arr,n))
                    return j - i;
          }
          if(count%2 == 0)
               i--;
          else
               j++;
          count += 1;
     }
     return n-1;
}


// most optimal approach
int mostOptimal(int arr[], int n){
     int minIndex = 0;
     int maxIndex = n-1;

     for(int i = 0; i < n-1; i++){
          if(arr[i] > arr[i+1]){
               minIndex = i;
               break;
          }
     }

     for(int i = n - 1; i > 0; i--){
          if(arr[i] < arr[i-1]){
               maxIndex = i;
               break;
          }
     }

     if(minIndex > maxIndex)
          return 0;

     std::cout << minIndex << " " << maxIndex << '\n';
     while(minIndex >= 0 || maxIndex < n){

          int data = arr[minIndex];
          while(minIndex >= 0){
               if(data > arr[minIndex]){
                    minIndex++;
                    break;
               }
               minIndex--;
          }

          data = arr[maxIndex];
          while(maxIndex < n){
               if(data < arr[maxIndex]){
                    maxIndex--;
                    break;
               }
               maxIndex++;
          }

          if(minIndex >= 0 && maxIndex < n)
               sort(arr+minIndex,arr+maxIndex+1);
          if(isSorted(arr,n))
               return maxIndex - minIndex;
     }
     return n-1;
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     std::cout << minimumDistance(arr,n) << '\n';
     std::cout << littleBetter(arr,n) << '\n';
     std::cout << mostOptimal(arr,n) << '\n';
}

/*
13
1 2 4 7 10 11 8 12 5 6 16 18 19
*/
