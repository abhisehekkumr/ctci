/*
     given two arrays one smaller and one longer find the smallest super subsequence
     in longer array resturn distance
*/

#include<iostream>
using namespace std;

// elements will be in order
void print(int bigger[], int n, int smaller[], int m, int element,int start = -1, int index = 0){
     if(m == 0){
          std::cout << start << " " << index-1 << '\n';
          return;
     }

     if(n == 0)
          return;

     if(bigger[0] == smaller[0]){

          if(smaller[0] == element)
               print(bigger+1,n-1,smaller+1,m-1,element,index,index+1);
          else
               print(bigger+1,n-1,smaller+1,m-1,element,start,index+1);
     }
     print(bigger+1,n-1,smaller,m,element,start,index+1);
}

int main(){
     int n;
     cin >> n;

     int smaller[n];
     for(int i = 0; i < n; i++)
          cin >> smaller[i];

     int m;
     cin >> m;

     int bigger[m];
     for(int i = 0; i < m; i++)
          cin >> bigger[i];
     print(bigger,m,smaller,n,smaller[0]);
}
/*
3
1 5 9
17
7 5 9 0 2 1 3 5 7 9 1 1 5 8 8 9 7
*/
