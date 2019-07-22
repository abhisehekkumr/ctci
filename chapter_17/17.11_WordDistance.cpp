/*
     find the distance between pair two words from file
*/
#include<iostream>
#include<fstream>
#include<climits>
#include<cmath>
#include<unordered_map>
#include<vector>
using namespace std;

void minDistance(string first_word, string second_word){
     string file_name = "dictionary.txt";
     fstream file(file_name);
     string a;

     unordered_map<string,vector<int>> map;

     if(first_word == second_word){
          std::cout << 0 << '\n';
          return;
     }

     int i = 0;
     while(file >> a){
          map[a].push_back(i);
          i++;
     }

     i = 0;
     int j = 0;

     if(map.count(first_word) && map.count(second_word)){
          int min = INT_MAX;
          while(i < map[first_word].size() && j < map[second_word].size()){
               int ans = abs(map[first_word][i] - map[second_word][j]);
               min = min < ans ? min : ans;

               if(map[first_word][i] > map[second_word][j])
                    j++;
               else
                    i++;
          }
          std::cout << min << '\n';
     }
}

int main(){
     string file_name = "dictionary.txt";
     fstream file(file_name);
     string a;

     string first_word;
     string second_word;
     cin >> first_word >> second_word;

     if(first_word == second_word){
          std::cout << 0 << '\n';
          return -1;
     }

     int i = 0;
     int first = -1,second = -1;
     int min = INT_MAX;
     minDistance(first_word,second_word);
     while(file >> a){
          if(a == first_word){
               //std::cout << "found a : " << a << '\n';
               first = i;
          }
          if(a == second_word){
               //std::cout << "found b : " << a << '\n';
               second = i;
          }
          if(first > -1 && second > -1){
               min = min < abs(first - second) ? min : abs(first - second);
               //std::cout << min << " min" << '\n';
               if(a == first_word)
                    first = -1;
               else
                    second = -1;
          }
          i++;
     }
     std::cout << min << '\n';
}
