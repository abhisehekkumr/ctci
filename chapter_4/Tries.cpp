/*
     Tries are used as a dictionary data structures
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class TrieNode{
public:
     bool terminalNode;
     TrieNode **children;

     TrieNode(){
          this->terminalNode = false;
          this->children = new TrieNode*[26];
          for(int i = 0; i < 26; i++)
               children[i] = NULL;
     }
};

class Trie{
     TrieNode *root;

     void add(TrieNode *root, string word){
          if(word.size() == 0){
               root->terminalNode = true;
               return;
          }
          int index = word[0]-'a';
          if(root->children[index]){
                add(root->children[index], word.substr(1));
                return;
           }
          TrieNode *child = new TrieNode();
          root->children[index] = child;
          add(root->children[index],word.substr(1));
     }

     bool find(TrieNode *root, string word){
          if(word.size() == 0){
               if(root->terminalNode)
                    return true;
               return false;
          }

          int index = word[0]-'a';
          if(root->children[index])
               return find(root->children[index],word.substr(1));
          return false;
     }

     void remove(TrieNode *root, string word){
          if(word.size() == 0){
               root->terminalNode = false;
               return;
          }

          int index = word[0]-'a';
          if(root->children[index])
               remove(root->children[index],word.substr(1));
          else
               return;

          TrieNode *child = root->children[index];
          bool flag = true;
          for(int i = 0; i < 26; i++){
               if(child->children[i])
                    flag = false;
          }
          if(flag)
               root->children[index] = NULL;
     }

     void printWords(TrieNode *root, string ans){
          if(root->terminalNode)
               std::cout << ans << '\n';
          char c = 'a';
          for(int i = 0; i < 26; i++){
               if(root->children[i])
                    printWords(root->children[i], ans + c);
               c += 1;
          }
     }

     void autoComplete(TrieNode *root, string word, string ans = ""){
          if(word.size() == 0){
               printWords(root,ans);
               return;
          }
          int index = word[0]-'a';
          if(root->children[index])
               autoComplete(root->children[index],word.substr(1),ans + word[0]);
     }

public:
     Trie(){
          root = new TrieNode();
     }

     void add(string word){
          add(root,word);
     }

     bool find(string word){
          return find(root,word);
     }

     void remove(string word){
          remove(root,word);
     }

     void autoComplete(string word){
          autoComplete(root,word);
     }
};

int main(){
     Trie *tree = new Trie();
     while(true){
          string word;
          cin >> word;

          if(word == "0")
               break;
          tree->add(word);
     }

     std::cout << tree->find("abhishek") << '\n';
     std::cout << tree->find("pandeer") << '\n';
     std::cout << tree->find("kumar") << '\n';

     tree->remove("abhishek");
     tree->remove("kumar");

     std::cout << tree->find("abhishek") << '\n';
     std::cout << tree->find("kumar") << '\n';
     tree->autoComplete("not");
}
