/*
     given BST print all possible sequence of elements from bst that can result
     in same BST
*/

#include<iostream>
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

int totalElement(TreeNode *root){
     if(!root)
          return 0;
     int left = totalElement(root->left);
     int right = totalElement(root->right);
     return left + right + 1;
}

void FillTree(int arrTree[], TreeNode *root, int &index){
     if(!root)
          return;
     arrTree[index++] = root->data;
     FillTree(arrTree,root->left,index);
     FillTree(arrTree,root->right,index);
}

void printRelativePermuataions(int *leftTree, int *rightTree, int *ans, int sizeleft,
                                                  int sizeright, int &count, int index = 1){

     if(sizeleft == 0 && sizeright == 0){
          for(int i = 0; i < index; i++)
               std::cout << ans[i] << ' ';
          std::cout << '\n';
          count += 1;
          return;
     }

     if(sizeleft){
          ans[index] = leftTree[0];
          printRelativePermuataions(leftTree+1, rightTree, ans, sizeleft-1,sizeright,count,index+1);
     }

     if(sizeright){
          ans[index] = rightTree[0];
          printRelativePermuataions(leftTree,rightTree+1,ans,sizeleft,sizeright-1,count,index+1);
     }
}

// this is my fucking algorithm
void printAllSequences(TreeNode *root){
     if(!root)
          return;
     int sizeleft = totalElement(root->left);
     int sizeright = totalElement(root->right);
     int index = 0;
     int leftTree[sizeleft], rightTree[sizeright];
     FillTree(leftTree,root->left, index);
     index = 0;
     FillTree(rightTree,root->right, index);

     int ans[sizeleft + sizeright + 1];
     ans[0] = root->data;
     int count = 0;
     std::cout << '\n';
     printRelativePermuataions(leftTree,rightTree,ans,sizeleft,sizeright,count);
     std::cout << '\n';
     std::cout << "total possible sequences are " << count << '\n';
     std::cout << '\n';
}

// 5 4 7 1 6 10 0
// 50 20 60 10 25 70 5 15 65 80 0
int main(){
     TreeNode *root = NULL;
     while(true){
          int data;
          cin >> data;
          if(data == 0)
               break;
          root = insert(root,data);
     }
     //display(root);
     printAllSequences(root);
}
