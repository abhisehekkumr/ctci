/*
     given unsorted linked list remove duplicate elements
*/
#include<iostream>
#include<unordered_map>
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

Node *remove(Node *head, int k){
     if(!head)
          return head;

     if(!head->next && head->data != k)
          return head;

     if(!head->next && head->data == k)
          return NULL;

     Node *list = NULL;
     Node *ptr = NULL;
     Node *prev = NULL;
     bool flag = true;
     while(head){
          if(head->data != k){
               if(!list){
                    list = head;
                    ptr  = head;
                    head = head->next;
               }
               else{
                    ptr->next = head;
                    head = head->next;
                    ptr = ptr->next;
               }
          }
          else if(flag){
               if(!list){
                    list = head;
                    ptr  = head;
                    head = head->next;
               }
               else{
                    ptr->next = head;
                    head = head->next;
                    ptr = ptr->next;
               }
               flag = false;
          }
          else
               head = head->next;
     }
     if(ptr)
          ptr->next = NULL;
     //display(list);
     return list;
}

Node *removeElement(Node *head, int k){
     if(!head)
          return head;

     if(!head->next && head->data != k)
          return head;

     if(!head->next && head->data == k)
          return NULL;

     Node *list = NULL;
     Node *ptr = NULL;
     Node *prev = NULL;
     while(head){
          if(head->data != k){
               if(!list){
                    list = head;
                    ptr  = head;
                    head = head->next;
               }
               else{
                    ptr->next = head;
                    head = head->next;
                    ptr = ptr->next;
               }
          }
          else
               head = head->next;
     }
     if(ptr)
          ptr->next = NULL;
     //display(list);
     return list;
}

Node *removeDuplucates(Node *head){

     if(!head || !head->next)
          return head;

     Node *ptr = head;
     while(ptr){
          head = remove(head,ptr->data);
          ptr = ptr->next;
     }
     return head;
}

Node *removeDuplucatesReal(Node *head){
     if(!head || !head->next)
          return head;
     Node *ptr = head;
     unordered_map<int,int> m;
     while(ptr){
          m[ptr->data]++;
          ptr = ptr->next;
     }
     ptr = head;
     while(ptr){
          if(m[ptr->data] > 1){
               head = removeElement(head,ptr->data);
               ptr = head;
          }
          else
               ptr = ptr->next;
     }
     return head;
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
     //display(head);
     head = removeDuplucatesReal(head);
     display(head);
}
