/*
     find the longest word made up of smallest words
*/

#include<iostream>
#include<string>
#include<fstream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
public:
     bool terminal;
     Node **children;

     Node(){
          terminal = false;
          children = new Node*[26];
          for(int i = 0; i < 26; i++)
               children[i] = NULL;
     }
};

// this will not work for simly reason that it will count how many words are on
// that path rather than checking that particuar word is made of two or not
// thus hash map is preffered
class Trie{
     Node *root;

     void insert(Node *root, string word){
          if(word.size() == 0){
               root->terminal = true;
               return;
          }
          int index = word[0] - 'a';
          if(root->children[index]){
               insert(root->children[index],word.substr(1));
               return;
          }

          Node *child = new Node();
          root->children[index] = child;
          insert(child,word.substr(1));
     }

     bool search(Node *root, string word){
          if(word.size() == 0)
               return root->terminal;
          int index = word[0]-'a';
          if(root->children[index])
               return search(root->children[index],word.substr(1));
          return false;
     }

     void concatedWords(Node *root, int count, string word = ""){

          if(count > 6 && root->terminal)
               std::cout << word << '\n';

          char c = 'a';
          for(int i = 0; i < 26; i++){
               if(root->children[i]){
                    if(root->children[i]->terminal)
                         concatedWords(root->children[i],count + 1, word + c);
                    else
                         concatedWords(root->children[i],count,word + c);
               }
               c++;
          }
     }

public:
     Trie(){
          root = new Node();
     }

     void insert(string word){
          insert(root,word);
     }

     bool search(string word){
          return search(root,word);
     }

     void concatedWords(){
          concatedWords(root,0);
     }
};


// only for two words
void concatedWords(vector<string> &v){
     unordered_map<string, bool> map;
     for(int i = 0; i < v.size(); i++)
          map[v[i]] = true;

     for(int i = 0; i < v.size(); i++){
          for(int j = 0; j < v[i].size(); j++){
               string left = v[i].substr(0,j);
               string right = v[i].substr(j);

               if(map.count(left) && map.count(right)){
                    std::cout << v[i] << " " << left << " " << right << '\n';
               }
          }
     }
}

bool compare(string a, string b){
     return a.size() > b.size();
}

bool found(unordered_map<string, bool> &map, bool original, string word){
     if(map.count(word) && !original)
          return map[word];

     for(int i = 0; i < word.size(); i++){
          string left = word.substr(0,i);
          string right = word.substr(i);
          if(map.count(left) && map[left] && found(map,false,right))
               return true;
     }
     map[word] = false;
     return false;
}

// for any words
void anyConcatetedWords(vector<string> &v){
     sort(v.begin(), v.end(), compare);
     unordered_map<string,bool> map;

     for(int i = 0; i < v.size(); i++)
          map[v[i]] = true;

     for(int i = 0; i < v.size(); i++){
          if(found(map,true,v[i])){
               std::cout << v[i] << '\n';
               break;
          }
     }
}
int main(){

     vector<string> v;

     string file_name = "dictionary.txt";
     fstream file(file_name);
     string word;

     while(file >> word)
          v.push_back(word);

     //concatedWords(v);
     anyConcatetedWords(v);
}
