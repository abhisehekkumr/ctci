/*
     given binary tree find the first common ancestor
*/
#include<iostream>
#include<queue>
#include<climits>
using namespace std;

struct TreeNode {
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
     Node *left;
     Node *right;
     Node *parent;

     Node(int data){
          this->data = data;
          this->left = NULL;
          this->right = NULL;
          this->parent = NULL;
     }
};

Node *insert(Node *root, int data){
     if(!root)
          return new Node(data);

     if(root->data > data){
          root->left = insert(root->left,data);
          root->left->parent = root;
     }
     else if(root->data < data){
          root->right = insert(root->right,data);
          root->right->parent = root;
     }
     return root;
}

void display(Node *root){
     if(!root)
          return;
     display(root->left);
     std::cout << root->data << ' ';
     display(root->right);
}

TreeNode *insert(){
     std::cout << "enter tree root : ";
     int data;
     cin >> data;
     TreeNode *root = new TreeNode(data);
     queue<TreeNode *> q;
     q.push(root);
     while(!q.empty()){
          TreeNode *node = q.front();
          q.pop();
          std::cout << "enter left child of " << node->data << " : ";
          int leftData;
          cin >> leftData;

          std::cout << "enter right child of " << node->data << " : ";
          int rightData;
          cin >> rightData;

          if(leftData){
               node->left = new TreeNode(leftData);
               q.push(node->left);
          }

          if(rightData){
               node->right = new TreeNode(rightData);
               q.push(node->right);
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

          if(node->left){
               std::cout << node->left->data << " ";
               q.push(node->left);
          }

          if(node->right){
               std::cout << node->right->data << " ";
               q.push(node->right);
          }
          std::cout << '\n';
     }
}

// most optimal approach
TreeNode *ancestorOptimal(TreeNode *root, int start, int end){
     if(!root)
          return NULL;

     if(root->data == start || root->data == end)
          return root;

     TreeNode *left = ancestorOptimal(root->left,start,end);
     TreeNode *right = ancestorOptimal(root->right,start,end);

     if(left && right)
          return root;
     return left != NULL ? left : right;
}

int depth(Node *root, int data, int height = 1){
     if(!root)
          return 0;

     if(root->data == data)
          return height;
     int left = depth(root->left,data,height+1);
     if(left != 0)
          return left;
     return depth(root->right,data,height+1);
}

Node *getNode(Node *root, int data){
     if(!root)
          return root;
     if(root->data == data)
          return root;
     Node *left = getNode(root->left,data);
     if(left)
          return left;
     return getNode(root->right,data);
}

Node *moveUp(Node *root,int k){
     int count = 0;
   while(root && count < k){
          count  += 1;
          root = root->parent;
     }
     return root;
}

Node *commonAncestor(Node *first, Node *second){
     if(!first)
          return second;
     if(!second)
          return first;
     if(first == second)
          return first;
     if(first->parent == second)
          return second;
     if(second->parent == first)
          return first;
     if(first->parent == second->parent)
          return first->parent;
     return commonAncestor(first->parent,second->parent);
}


// time complexity is O(d) where d is the depth
int ancestorParent(Node *root, int start, int end){
     if(!root)
          return 0;

     int start_depth = depth(root,start);
\\int end_depth = depth(root,end);
     Node *first = getNode(root,start);
     Node *second = getNode(root,end);

     if(start_depth > end_depth)
          first = moveUp(first,start_depth - end_depth);

     if(end_depth > start_depth)
          second = moveUp(second,end_depth-start_depth);

     Node *result = commonAncestor(first,second);
     if(!result)
          return 0;
     return result->data;
}

// 20 10 30 5 15 0 0 3 7 0 17 0 0 0 0 0 0
// 10 5 4 15 12 11 14 13 16 0
int main(){
     /*
     TreeNode *root = insert();
     int start, end;
     cin >> start >> end;
     TreeNode *node = ancestorOptimal(root,start,end);

     if(node)
          std::cout << node->data << '\n';
     else
          std::cout << "nothing" << '\n';
          */
     Node *root = NULL;
     while(true){
          int data;
          cin >> data;
          if(data == 0)
               break;
          root = insert(root,data);
     }
     int start ,end;
     cin >> start >> end;
     std::cout << ancestorParent(root,start,end) << '\n';
}
