/*
     given BST make d linked list level order wise where d is the depth of the Tree
     for all posisble depths
*/
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
     int data;
     TreeNode *left;
     TreeNode *right;

     TreeNode(int data){
          this->data = data;
          this->left = NULL;
          this->right = NULL;
     }
};

struct Node {
     int data;
     Node *next;

     Node(int data){
          this->data = data;
          this->next = NULL;
     }
};

TreeNode *insert(TreeNode *root, int data){
     if(!root)
          return new TreeNode(data);
     if(root->data > data)
          root->left = insert(root->left,data);
     else if(root->data < data)
          root->right = insert(root->right,data);
     return root;
}

void display(TreeNode *root){
     if(!root)
          return;
     display(root->left);
     std::cout << root->data << ' ';
     display(root->right);
}

int height(TreeNode *root){
     if(!root)
          return 0;
     int left = height(root->left);
     int right = height(root->right);
     return (left > right ? left : right) + 1;
}

void linkedList(TreeNode *root, Node **head , int h){
     if(!root)
          return;

     if(h == 1){
          Node *node = new Node(root->data);
          if(!(*head))
               (*head) = node;
          else{
               node->next = (*head);
               (*head) = node;
          }
          return;
     }
     linkedList(root->right,head,h-1);
     linkedList(root->left,head,h-1);
}

// this is O(h*h) solution where h is height of tree where if h can be log n or n
void BSTtoLinkedList(TreeNode *root){
     int h = height(root);
     vector<Node *> v;

     for(int i = 0; i < h; i++){
          Node *node = NULL;
          linkedList(root,&node,i+1);
          v.push_back(node);
     }

     for(int i = 0; i < v.size(); i++){
          Node *ptr = v[i];
          while(ptr){
               std::cout << ptr->data << ' ';
               ptr = ptr->next;
          }
          std::cout << '\n';
     }
}

void buildLinkedList(TreeNode *root, Node *arr[], int h){
     if(!root)
          return;

     Node *node = new Node(root->data);
     if(arr[h] == NULL)
          arr[h] = node;
     else{
          node->next = arr[h];
          arr[h] = node;
     }
     buildLinkedList(root->right,arr,h+1);
     buildLinkedList(root->left,arr,h+1);
}

// best approach till now O(n)
void optmal(TreeNode *root){
     int h = height(root);
     Node *arr[h];
     for(int i = 0; i < h; i++)
          arr[i] = NULL;
     buildLinkedList(root,arr,0);
     for(int i = 0; i < h; i++){
          Node *ptr = arr[i];
          while(ptr){
               std::cout << ptr->data << ' ';
               ptr = ptr->next;
          }
          std::cout << '\n';
     }
}

int main(){
     TreeNode *root = NULL;
     while(true){
          int data;
          cin >> data;
          if(data == -1)
               break;
          root = insert(root,data);
     }
     //display(root);
     //std::cout << '\n';
     BSTtoLinkedList(root);
     optmal(root);
}

/*
100 50 40 30 20 10 12 25 35 45 55 60 70 80 90 65 75 85 95 110 1120 120 130 140
150 160 170 180 190 200 10 105 115 125 135 145 155 165 175 185 195 -1

*/
