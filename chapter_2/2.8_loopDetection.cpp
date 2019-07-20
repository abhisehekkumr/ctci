/*
     detect loop in linked list if exits then return starting node of loop
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
     while (head) {
          std::cout << head->data << ' ';
          head = head->next;
     }
     std::cout << '\n';
}

void makeLoop(Node *head){
     int n = 5;
     Node *ptr = head;
     int count = 0;

     while(ptr && count < n){
          count++;
          ptr = ptr->next;
     }

     Node *node = ptr;

     while(ptr->next)
          ptr = ptr->next;
     ptr->next = node;
}

// O(n) space complexity
Node *DetectLoopMap(Node *head){
     if(!head)
          return NULL;

     unordered_map<Node *,int> m;
     Node *ptr = head;
     while(ptr){
          if(m.count(ptr))
               return ptr;
          m[ptr]++;
          ptr = ptr->next;
     }
     return NULL;
}

Node *DetectLoopOptimal(Node *head){
     if(!head)
          return head;

     if(!head->next)
          return NULL;

     Node *slow = head;
     Node *fast = head->next;

     while(fast && fast->next){
          slow = slow->next;
          fast = fast->next->next;
          if(slow == fast)
               break;
     }

     if(!fast || !fast->next)
          return NULL;

     slow = head;
     while(fast->next != slow){
          fast = fast->next;
          slow = slow->next;
          std::cout << slow->data << " " << fast->data << '\n';
     }
     return slow;
}

int main(){
     Node *head = NULL;
     while(true){
          int data;
          cin >> data;
          if(data == -1)
               break;
          head = insert(head,data);
     }
     makeLoop(head);
     //display(head);
     Node *node = DetectLoopOptimal(head);
     if(node)
          std::cout << "loop node is : " << node->data << '\n';
     else
          std::cout << "no loop in linked list" << '\n';
}
