/*
     given numbers form keypad print all possible valid english words
*/
#include<fstream>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

class TrieNode{
public:
     bool terminal;
     TrieNode **children;

     TrieNode(){
          terminal = false;
          children = new TrieNode*[26];
          for(int i = 0; i < 26; i++)
               children[i] = NULL;
     }
};

class Trie{
     TrieNode *root;

     void insert(TrieNode *root, string word){
          if(word.size() == 0){
               root->terminal = true;
               return;
          }
          int index = word[0]-'a';
          if(root->children[index]){
               insert(root->children[index],word.substr(1));
               return;
          }
          TrieNode *child = new TrieNode();
          root->children[index] = child;
          insert(root->children[index],word.substr(1));
     }

     bool find(TrieNode *root, string word){
          if(word.size() == 0){
               return root->terminal;
          }
          int index = word[0]-'a';
          if(root->children[index])
               return find(root->children[index],word.substr(1));
          return false;
     }

     void remove(TrieNode *root, string word){
          if(word.size() == 0){
               root->terminal = false;
               return;
          }
          int index = word[0] - 'a';
          if(root->children[index]){
               remove(root->children[index],word.substr(1));
          }
          else
               return;

          TrieNode *child = root->children[index];
          for(int i = 0; i < 26; i++){
               if(child->children[i])
                    return;
          }
          root->children[index] = NULL;
          delete child;
     }

public:
     Trie(){
          root = new TrieNode();
     }

     void insert(string word){
          insert(root, word);
     }

     bool find(string word){
          return find(root,word);
     }

     void remove(string word){
          remove(root,word);
     }

     TrieNode *getChild(TrieNode *root,char word){
          int index = word - 'a';
          if(root->children[index])
               return root->children[index];
          return NULL;
     }

     TrieNode *getRoot(){
          return root;
     }
};

unordered_map<string, bool> *readDictionary(string file_name){
     vector<string> *v = new vector<string>();
     ifstream infile("dictionay.txt");
     string str;
     while(infile >> str)
          v->push_back(str);

     unordered_map<string, bool> *map = new unordered_map<string,bool>();
     for(int i = 0; i < v->size(); i++)
          (*map)[(*v)[i]] = true;
     delete v;
     return map;
}

string *getDigitCodes(){
     string *str =  new string[10];
     str[0] = "";
     str[1] = "";
     str[2] = "abc";
     str[3] = "def";
     str[4] = "ghi";
     str[5] = "jkl";
     str[6] = "mno";
     str[7] = "pqrs";
     str[8] = "tuv";
     str[9] = "wxyz";
     return str;
}

int power(int n){
     int base = 4;
     int res = 1;
     while(n){
          if(n & 1)
               res = res*base;
          base = base*base;
          n = n >> 1;
     }
     return res;
}

int numDigits(int number){
     int count = 0;
     while(number){
          count += 1;
          number = number/10;
     }
     return count;
}

int fillPossibleWords(string number, string *digit, string *output){
     if(number.size() == 0){
          output[0] = "";
          return 1;
     }

     int count = fillPossibleWords(number.substr(1), digit,output);
     string currentDigit = digit[number[0]-'0'];

     for(int i = 0; i < count; i++){
          string temp = output[i];
          output[i] = currentDigit[0] + output[i];
          int jump = count;
          for(int j = 1; j < currentDigit.size(); j++){
               output[i + jump] = currentDigit[j] + temp;
               jump += count;
          }
     }
     return count*currentDigit.size();
}

// the time complexity of this code is O(4^n) because one digit can have maximum
// 4 characters. space complexity is also O(4^n) for storing result
void printAllWords(unordered_map<string,bool> *map, string *digit, string number){
     int size = power(number.size());
     string *arr = new string[size];
     int totalStrings = fillPossibleWords(number,digit,arr);

     for(int i = 0; i < totalStrings; i++){
          if(map->count(arr[i]))
               std::cout << arr[i] << '\n';
     }
}

// same above code but optimized in term of space , O(n) where n is the size of
// the string
void printAllWordsSpaceOptimized(unordered_map<string,bool> *m, string *digit, string number, string ans = ""){

     if(number.size() == 0){
          if(m->count(ans))
               std::cout << ans << '\n';
          return;
     }

     string currentDigit = digit[number[0]-'0'];
     for(int i = 0; i < currentDigit.size(); i++)
          printAllWordsSpaceOptimized(m,digit,number.substr(1),ans+currentDigit[i]);
}

void printTrieValidNumbers(string number, int n, string *digit, Trie tree, TrieNode *c, string ans = ""){

     if(ans.size() == n){
          if(c->terminal)
               std::cout << ans << '\n';
          return;
     }

     string currentDigit = digit[number[0]-'0'];
     for(int i = 0; i < currentDigit.size(); i++){
          TrieNode *child = tree.getChild(c,currentDigit[i]);
          if(child){
               printTrieValidNumbers(number.substr(1),n,digit,tree,child,ans+currentDigit[i]);
          }
     }
}

void printAllWordsTrie(unordered_map<string,bool> *map, string *digit, string number){
     Trie tree;
     unordered_map<string,bool> :: iterator it;
     for(it = map->begin(); it != map->end(); it++)
          tree.insert(it->first);

     printTrieValidNumbers(number,number.size(),digit,tree,tree.getRoot());
}

unordered_map<char,int> fillMap(){
     unordered_map<char,int> map;
     map['a'] = 2;
     map['b'] = 2;
     map['c'] = 2;
     map['d'] = 3;
     map['e'] = 3;
     map['f'] = 3;
     map['g'] = 4;
     map['h'] = 4;
     map['i'] = 4;
     map['j'] = 5;
     map['k'] = 5;
     map['l'] = 5;
     map['m'] = 6;
     map['n'] = 6;
     map['o'] = 6;
     map['p'] = 7;
     map['q'] = 7;
     map['r'] = 7;
     map['s'] = 7;
     map['t'] = 8;
     map['u'] = 8;
     map['v'] = 8;
     map['w'] = 9;
     map['x'] = 9;
     map['y'] = 9;
     map['z'] = 9;
     return map;
}

void printAllWordsLookUp(unordered_map<string,bool> *map, string *digit, string number){
     unordered_map<char,int> charMap = fillMap();
     unordered_map<string,vector<string>> lookup;

     unordered_map<string,bool> :: iterator it;
     for(it = map->begin(); it != map->end(); it++){
          string str = it->first;
          string ans = "";
          for(int i = 0; i < str.size(); i++)
               ans += char(charMap[str[i]] + '0');
          lookup[ans].push_back(str);
     }

     if(lookup.count(number)){
          for(int i = 0; i < lookup[number].size(); i++)
               std::cout << lookup[number][i] << '\n';
     }
}

bool found(string mid, string word){
     if(mid.size() < word.size())
          return false;
     for(int i = 0; i < word.size(); i++){
          if(mid[i] != word[i])
               return false;
     }
     return true;
}

inline int min(int a, int b){
     return a < b ? a : b;
}

bool isBigger(string str, string word){
     for(int i = 0; i < min(str.size(), word.size()); i++){
          if(str[i] < word[i])
               return true;
     }
     return false;
}

bool binarySearch(vector<string> &v, string word, int start, int end){
     if(start > end)
          return false;

     int mid = (start + end)/2;

     string str = v[mid];
     //std::cout << "mid " << str << " " << word << " " << start << " " << end << '\n';
     if(found(str,word))
          return true;

     if(isBigger(str,word))
          return binarySearch(v,word,mid+1,end);

     return binarySearch(v,word,start,mid-1);
}

void printUsingBinarySeach(vector<string> &v, string *digit, string number, int n, string ans = ""){

     if(ans.size() == n){
          std::cout << ans << '\n';
          return;
     }

     string currentDigit = digit[number[0]-'0'];
     int start = 0;
     int end = v.size()-1;
     for(int i = 0; i < currentDigit.size(); i++){
          if(binarySearch(v,ans+currentDigit[i],start,end)){
               //std::cout << "ans : " << ans+currentDigit[i] << '\n';
               printUsingBinarySeach(v,digit,number.substr(1),n,ans + currentDigit[i]);
          }
     }
}

void printAllWordsBinarySearch(unordered_map<string,bool> *map, string *digit,string number){
     vector<string> v;
     unordered_map<string,bool> :: iterator it;

     for(it = map->begin(); it != map->end(); it++)
          v.push_back(it->first);
     sort(v.begin(), v.end());
     printUsingBinarySeach(v,digit,number,number.size());
}

int main(){
     string file_name = "dictionay.txt";
     unordered_map<string,bool> *map = readDictionary(file_name);
     string *digits = getDigitCodes();


     // input from user as number;
     string number;
     cin >> number;

     std::cout << "using trie" << '\n';
     printAllWordsTrie(map,digits,number);
     std::cout << "using binary search" << '\n';
     printAllWordsBinarySearch(map,digits,number);
     std::cout << "hash map using number lookup" << '\n';
     printAllWordsLookUp(map,digits,number);
     std::cout << "worst case time->O(4^n) space->O(n)" << '\n';
     printAllWordsSpaceOptimized(map,digits,number);
     std::cout << "worst case time->O(4^n) space->O(4^n) : " << '\n';
     printAllWords(map,digits,number);
}
