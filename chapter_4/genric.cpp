/*
     genric tries where we can have as many children for particular root as we want
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class TreeNode{
public:
     int data;
     vector<TreeNode *> children;

     TreeNode(int data){
          this->data = data;
     }
};

class GenricTree{
     TreeNode *root;

     TreeNode *insert(TreeNode *root){
          std::cout << "enter root : " << ' ';
          int data;
          cin >> data;

          TreeNode *node = new TreeNode(data);
          root = node;
          queue<TreeNode *> q;

          q.push(root);
          while(!q.empty()){
               TreeNode *node = q.front();
               q.pop();
               int n;
               std::cout << "how many children of " << node->data << " : ";
               cin >> n;
               for(int i = 0; i < n; i++){
                    int data;
                    std::cout << "enter " << i+1 << " child of " << node->data << " : ";
                    cin >> data;
                    TreeNode *child = new TreeNode(data);
                    node->children.push_back(child);
                    q.push(child);
               }
          }
          return root;
     }

     void print(TreeNode *root){

          if(!root)
               return;
          queue<TreeNode *> q;
          q.push(root);
          while(!q.empty()){
               TreeNode *node = q.front();
               q.pop();
               std::cout << node->data << " : ";
               for(int i = 0; i < node->children.size(); i++){
                    TreeNode *child = node->children[i];
                    std::cout << child->data << ' ';
                    q.push(child);
               }
               std::cout << '\n';
          }
     }

public:
     GenricTree(){
          root = NULL;
     }

     void insert(){
          root = insert(root);
     }

     void print(){
          print(root);
     }
};

int main(){
     GenricTree *tree  = new GenricTree();
     tree->insert();
     tree->print();
}
