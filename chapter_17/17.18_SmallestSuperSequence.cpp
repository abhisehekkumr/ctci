/*
     given two arrays one smaller and one longer find the smallest super subsequence
     in longer array resturn distance
*/

#include<iostream>
#include<unordered_map>
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

int smallestSuperSequence(int bigger[], int smaller[], int n, int m){
     unordered_map<int,bool> map;
     for(int i = 0; i < m; i++)
          map[smaller[i]] = true;

     int start = 0, end = 999999999;

     for(int i = 0; i < n - 2; i++){
          bool found = true;
          if(map.count(bigger[i])){
               int j;
               int count = 0;
               for(j = i; j < n; j++){
                    if(map.count(bigger[j])){
                         if(map[bigger[j]]){
                              map[bigger[j]] = false;
                              count += 1;
                         }
                         else{
                              found = false;
                              break;
                         }
                    }

                    if(count == map.size())
                         break;
               }
               if(found){
                    if((end - start) > (j - i)){
                         start = i;
                         end = j;
                         std::cout << i << " " << j << '\n';
                    }
               }

               for(int j = 0; j < map.size(); j++)
                    map[smaller[j]] = true;
          }
     }
     std::cout << start << " "  << end << '\n';
     return 0;
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
     //print(bigger,m,smaller,n,smaller[0]);
     std::cout << smallestSuperSequence(bigger,smaller,m,n) << '\n';
}
/*
3
1 5 9
17
7 5 9 0 2 1 3 5 7 9 1 1 5 8 8 9 7
*/
