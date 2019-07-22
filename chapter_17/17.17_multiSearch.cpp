#include<iostream>
#include<vector>
#include<unordered_map>
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

     void printInPath(Node *root, vector<string> &v, string word, string ans = ""){
          if(root->terminal){
               v.push_back(ans);
               root->terminal = false;
          }

          if(word.size() == 0){
               return;
          }

          int index = word[0] - 'a';
          if(root->children[index]){
               printInPath(root->children[index], v, word.substr(1), ans + word[0]);
               return;
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

     void allWords(string word){
          vector<string> v;
          printInPath(root,v,word);

          for(int i = 0; i < v.size(); i++)
               std::cout << v[i] << '\n';
     }
};

bool found(string small, string bigger){
     int j = 0;
     for(int i = 0; i < bigger.size() - small.size() + 1; i++){
          if(bigger[i] == small[j]){
               for(int k = i; k < i + small.size(); k++){
                    if(k < bigger.size() && j < small.size() && bigger[k] == small[j])
                         j++;
                    else
                         break;
               }

               if(j == small.size())
                    return true;
               j = 0;
          }
     }
     return false;
}

// time complexity is O(tkp) where t is total number of strings , k is the size of
// the small and b is the size of bigger string
vector<string> getStrings(string arr[], int n, string pattern){
     vector<string> v;
     for(int i = 0; i < n; i++){
          if(found(arr[i],pattern))
               v.push_back(arr[i]);
     }
     return v;
}

void printWords(string arr[], int n, string pattern){
     Trie tree;

     for(int i = 0; i < pattern.size(); i++){
          for(int j = i; j < pattern.size(); j++){
               string str = pattern.substr(i,j);
               tree.insert(str);
          }
     }

     vector<string> v;
     for(int i = 0; i < n; i++){
          if(tree.search(arr[i]))
               v.push_back(arr[i]);
     }

     for(int i = 0; i < v.size(); i++)
          std::cout << v[i] << '\n';
}

void printWordsbetter(string arr[], int n, string pattern){
     Trie tree;
     for(int i = 0; i < n; i++)
          tree.insert(arr[i]);

     for(int i = 0; i < pattern.size(); i++){
          tree.allWords(pattern.substr(i));
     }
}

int main(){
     int n;
     cin >> n;

     string arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     string pattern;
     cin >> pattern;
     vector<string> v = getStrings(arr,n,pattern);
     std::cout << "**************************" << '\n';
     std::cout << "wors case result O(TPS)" << '\n';
     std::cout << "**************************" << '\n';
     for(int i = 0; i < v.size(); i++)
          std::cout << v[i] << '\n';
     std::cout << '\n';
     std::cout << "**************************" << '\n';
     std::cout << "litter beeter case result O(P*P + T)" << '\n';
     std::cout << "**************************" << '\n';
     printWords(arr,n,pattern);
     std::cout << "**************************" << '\n';
     std::cout << "beter case result O(TK + PK)" << '\n';
     std::cout << "**************************" << '\n';
     printWordsbetter(arr,n,pattern);
}

/*
6
is ppi hi sis i ssippi
mississippi
*/
