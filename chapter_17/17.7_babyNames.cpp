/*
     given baby names and their frequencies and find the actual frequencies of all
     names if one name as alternative
*/

#include<iostream>
#include<string>
#include<queue>
#include<unordered_set>
#include<vector>
using namespace std;

struct BabyNames{
     string name;
     int count;
};

struct BabyAlternatives{
     string name;
     string alt;
};

void printTable(BabyNames babies[], BabyAlternatives alternative[], int n, int m){
     vector<unordered_set<string>> v;

     for(int i = 0; i < m; i++){
          if(alternative[i].name == "" && alternative[i].alt == "")
               continue;
          queue<BabyAlternatives> q;
          q.push(alternative[i]);
          unordered_set<string> set;
          while(!q.empty()){
               BabyAlternatives baby = q.front();
               q.pop();

               //std::cout << baby.name << " " << baby.alt << '\n';

               string str = "";
               if(baby.name == "" && baby.alt == "")
                    continue;

               if(baby.name == ""){
                    set.insert(baby.alt);
                    str = baby.alt;
               }
               else if(baby.alt == ""){
                    set.insert(baby.name);
                    str = baby.name;
               }
               else{
                    string name = baby.name;
                    baby.name = "";
                    q.push(baby);
                    set.insert(name);
                    str = name;
               }

               if(str == "")
                    continue;

               for(int j = 0; j < m; j++){
                    if(alternative[j].name == "" && alternative[j].alt == "")
                         continue;
                    if(alternative[j].name == str){
                         q.push(alternative[j]);
                         alternative[j].name = "";
                    }
                    if(alternative[j].alt == str){
                         q.push(alternative[j]);
                         alternative[j].alt = "";
                    }
               }
          }

          if(set.size() > 0)
               v.push_back(set);
     }

     for(int i = 0; i < v.size(); i++){
          unordered_set<string> :: iterator it;
          for(it  = v[i].begin(); it != v[i].end(); it++)
               std::cout << (*it) << ' ';
          std::cout << '\n';
     }

     std::cout << '\n';
     std::cout << "printing frequencies of actual names includig alternative" << '\n';
     int arr[v.size()];
     for(int i = 0; i < v.size(); i++)
          arr[i] = 0;
     std::cout << "--------------------------" << '\n';
     std::cout << "|    name   |  frequency   |" << '\n';
     std::cout << "--------------------------" << '\n';
     for(int i = 0; i < v.size(); i++){
          for(int j = 0; j < n; j++){
               if(v[i].find(babies[j].name) == v[i].end())
                    continue;
               arr[i] += babies[j].count;
               //std::cout << i << " " << babies[j].name << " " << babies[j].count << '\n';
          }
          unordered_set<string> :: iterator it;
          it = v[i].begin();
          std::cout << "|" << " " << (*it) << "  " << "|" << "   " << arr[i] << "      |" << '\n';
     }
}

int main(){
     int n = 9;
     int m = 5;
     BabyNames babies[n];
     for(int i = 0; i < n; i++){
          string name;
          int count;
          cin >> babies[i].name >> babies[i].count;
     }

     BabyAlternatives alternative[m];
     for(int i = 0; i < m; i++)
          cin >> alternative[i].name >> alternative[i].alt;
     std::cout << '\n';
     std::cout << '\n';
     std::cout << "all alternative names" << '\n';
          printTable(babies,alternative,n,m);
}
/*
john 10
jon 3
davis 2
kari 3
johnny 11
carlton 8
carleton 2
jonathan 9
carrie 5
jonathan john
jon johnny
johnny john
kari carrie
carlton carleton
*/
