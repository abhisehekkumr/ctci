/*
     given birth and death of persons in range 1900 and 2000 find the year in
     which most people are alive, year of death of shoud be counted as alive year
*/

#include<iostream>
#include<algorithm>
#define MIN_YEAR 1900
#define MAX_YEAR 2000
using namespace std;

struct Person{
     int birth;
     int death;
};

// complexity of this algo is O(RP) where R is the range of the years and P is
// total number of persons whereas space required is constant
int mostAliveYear(Person arr[], int n){
     int max_alive = 0;
     int max_year = MIN_YEAR;


     for(int i = MIN_YEAR; i <= MAX_YEAR; i++){
          int alive = 0;
          for(int j = 0; j < n; j++){
               if(arr[j].birth <= i && i <= arr[j].death)
                    alive++;
          }

          if(max_alive < alive){
               max_year = i;
               max_alive = alive;
          }
     }
     return max_year;
}

// using sorting O(p log p), solution approach is like when any person is born
// one person is added irrespective of date and when person died then one persons
// decreses thus make making count stable we can find the actual year where maximum
// persons where alive

int max_alive_year(int alive[], int dead[], int n){
     sort(alive, alive+n);
     sort(dead,dead+n);

     int a = 0, d = 0, count = 0, year = MIN_YEAR, max_count = 0;
     while(a < n){
          if(alive[a] <= dead[d]){
               count += 1;
               a++;

               if(count > max_count){
                    max_count = count;
                    year = alive[a-1];
               }
          }
          else
               d++;
     }
     return year;
}

// creating count frequency for every year
// space complexity is O(min + max + 1) and run time is O(PY + R)
// where y is year a person lived

int mostAliveYear_little_better(Person arr[], int n){
     int count[MAX_YEAR - MIN_YEAR + 1];

     for(int i = 0; i < (MAX_YEAR - MIN_YEAR + 1); i++)
          count[i] = 0;

     for(int i = 0; i < n; i++){
          for(int j = arr[i].birth; j <= arr[i].death; j++)
               count[j - MIN_YEAR]++;
     }

     int max = 0;
     int year = 0;
     for(int i = 0; i < (MAX_YEAR - MIN_YEAR + 1); i++){
          if(max < count[i]){
               max = count[i];
               year = MIN_YEAR + i;
          }
     }
     return year;
}

// O(R + P) ans O(R) space complexity
// alive will be mormaly added to the group but dead count will be
// subtrated from the count
int mostOptimal(Person arr[], int n){
     int count[MAX_YEAR - MIN_YEAR + 1];
     for(int i = 0; i < (MAX_YEAR - MIN_YEAR + 1); i++)
          count[i] = 0;

     for(int i = 0; i < n; i++){
          count[arr[i].birth - MIN_YEAR]++;
          count[arr[i].death - MIN_YEAR + 1]--;
     }

     int max = 0, alive = 0;
     int year = MIN_YEAR;
     for(int i = 0; i < (MAX_YEAR - MIN_YEAR + 1); i++){
          alive += count[i];
          if(alive > max){
               max = alive;
               year = MIN_YEAR + i;
          }
     }
     return year;
}

int main(){
     int n;
     cin >> n;

     int alive[n], dead[n];
     for(int i = 0; i < n; i++)
          cin >> alive[i];
     for(int i = 0; i < n; i++)
          cin >> dead[i];

     Person arr[n];
     for(int i = 0; i < n; i++){
          arr[i].birth = alive[i];
          arr[i].death = dead[i];
     }

     std::cout << mostAliveYear(arr,n) << '\n';
     std::cout << max_alive_year(alive,dead,n) << '\n';
     std::cout << mostAliveYear_little_better(arr,n) << '\n';
     std::cout << mostOptimal(arr,n) << '\n';
}

/*
10
1912 1920 1910 1901 1910 1923 1913 1990 1983 1975
1915 1990 1998 1972 1998 1982 1998 1998 1999 1994
*/
