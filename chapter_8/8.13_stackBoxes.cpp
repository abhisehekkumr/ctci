/*
     given array of boxes having height, width and depth find the maximum possible
     height of stack if we can only place one box above only the one in stack if
     it is less than in all three dimestions
*/

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

class Boxes{
public:
     int height;
     int width;
     int depth;
};

inline int max(int a, int b){
     return a > b ? a : b;
}

bool isSafeToPlace(Boxes obj1, Boxes obj2){
     //std::cout << "this is checking" << '\n';
     //std::cout << obj1.height << " " << obj1.width << " " << obj1.depth << '\n';
     //std::cout << obj2.height << " " << obj2.width << " " << obj2.depth << '\n';
     return (obj1.height < obj2.height && obj1.width < obj2.width && obj1.depth < obj2.depth);
}

int maxHeight(Boxes arr[], int size, Boxes obj){
     if(size == 0)
          return 0;

     int isIncluded = 0;
     if(isSafeToPlace(arr[0], obj))
          isIncluded = maxHeight(arr+1,size-1,arr[0]) + arr[0].height;

     int notIncludes = maxHeight(arr+1,size-1,obj);
     return max(notIncludes, isIncluded);
}

int solve(Boxes arr[], int size, Boxes obj, int *dp){
     if(size == 0)
          return 0;

     if(dp[size] > -1)
          return dp[size];

     int isIncluded = 0;
     if(isSafeToPlace(arr[0], obj))
          isIncluded = solve(arr+1,size-1,arr[0],dp) + arr[0].height;

     int notIncluded = solve(arr+1,size-1,obj,dp);

     dp[size] = max(isIncluded, notIncluded);
     return dp[size];
}

int maxHeightDP(Boxes arr[], int size, Boxes obj){
     int *dp = new int[size+1];
     for(int i = 0; i <= size; i++)
          dp[i] = -1;
     return solve(arr,size,obj,dp);
}

bool comapre(Boxes obj1, Boxes obj2){
     return obj1.height > obj2.height;
}

int main(){
     int n;
     cin >> n;

     Boxes arr[n];
     for(int i = 0; i < n; i++){
          cin >> arr[i].height >> arr[i].width >> arr[i].depth;
     }

     sort(arr,arr+n,comapre);
     std::cout << "boxes after sorting" << '\n';
     for(int i = 0; i < n; i++){
          std::cout << arr[i].height << " " << arr[i].width << " " << arr[i].depth << '\n';
     }
     Boxes obj;
     obj.height = INT_MAX;
     obj.width = INT_MAX;
     obj.depth = INT_MAX;
     std::cout << maxHeight(arr,n,obj) << '\n';
     std::cout << maxHeightDP(arr,n,obj) << '\n';
}
