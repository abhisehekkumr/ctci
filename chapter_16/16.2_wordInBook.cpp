/*
     given array of words find the freuqncy of the given word. what if we have to
     run this problem again and again
*/

#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class TrieNode{
public:
     int count;
     bool terminal;
     TrieNode **children;

     TrieNode(){
          count = 0;
          terminal = false;
          children = new TrieNode*[26];
          for(int i = 0; i < 26; i++)
               children[i] = NULL;
     }
};


// space complexity is less then the hash map and we dont store almost smae
// words again and again, but seeach complexity is tern out to be O(l), where
// l is the size of the word, but space is very much optimized
// as this algo will be run many times overall algo will turn out to be O(q*l);;
class Trie{
     TrieNode *root;

     void insert(TrieNode *root, string word){
          if(word.size() == 0){
               root->terminal = true;
               root->count = root->count + 1;
               return;
          }

          int index = word[0]-'a';
          if(root->children[index]){
               insert(root->children[index],word.substr(1));
               return;
          }
          TrieNode *node = new TrieNode();
          root->children[index] = node;
          insert(root->children[index],word.substr(1));
     }

     int freuqncy(TrieNode *root, string word){
          if(word.size() == 0){
               return root->count;
          }
          int index = word[0]-'a';
          if(root->children[index])
               return freuqncy(root->children[index], word.substr(1));
          return 0;
     }

public:
     Trie(){
          root = new TrieNode();
     }

     void insert(string word){
          insert(root,word);
     }

     int freuqncy(string word){
          return freuqncy(root,word);
     }
};

// O(n) time complexity and O(1) space, what as we are working with book and we
// will run this algo again and again thaen this complexity will turn out to be
// O(q*n) where in worst case it is not good, as book can be rich in vocabulary
int WordFrequency(string *arr, int n, string word){
     int count = 0;
     for(int i = 0; i < n; i++){
          if(arr[i] == word)
               count += 1;
     }
     return count;
}

//As for frequency we have to scan book at least once, and we have to tell freuqncy
// again and again, thus hash map will be better option. this is good solution but
// it is not good in term in form of space because even if there is change in one
// character then we have to store them into another place, thus trie will be must
// better for space optimization
int WordFrequencyHash(string *arr, int n, string word){
     unordered_map<string,int> m;
     for(int i = 0; i < n; i++)
          m[arr[i]]++;
     return m[word];
}

int main(){
     string arr[] = {"abc", "def", "ghi","mno","abc", "def", "ghi","mno","abc", "def", "ghi","abc","mno"};
     int n = 13;
     string ans;
     cin >> ans;
     std::cout << WordFrequency(arr,n,ans) << '\n';
     std::cout << WordFrequencyHash(arr,n,ans) << '\n';

     Trie tree;
     for(int i = 0; i < n; i++)
          tree.insert(arr[i]);
     std::cout << tree.freuqncy(ans) << '\n';
}
