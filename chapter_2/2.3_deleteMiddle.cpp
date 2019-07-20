/*
     delete middle node given access to that node only
*/
#include<iostream>
using namespace std;

struct Node{
     int data;
     Node *next;

     Node(int data){
          this->data = data;
          this->next = NULL;
     }
};

Node *insert(Node *head, int data){
     Node *node = new Node(data);
     if(!head)
          return node;

     Node *ptr = head;
     while(ptr->next)
          ptr = ptr->next;
     ptr->next = node;
     return head;
}

void display(Node *head){
     if(!head)
          return;

     while(head){
          std::cout << head->data << ' ';
          head = head->next;
     }
     std::cout << '\n';
}

void deleteMiddle(Node *head){
     if(!head || !head->next)
          return;

     Node *node = head->next;
     head->data = node->data;
     head->next = node->next;
}

int main(){
     Node *head = NULL;
     while(true){
          int element;
          cin >> element;
          if(element == -1)
               break;
          head = insert(head,element);
     }
     Node *ptr = head;
     for(int i = 0; i < 3; i++)
          ptr = ptr->next;
     deleteMiddle(ptr);
     display(head);
}
