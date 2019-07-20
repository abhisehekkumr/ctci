/*
     given two linked list find intersection node
*/

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

struct Node {
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

Node *makeIntersection(Node *head1, Node *head2){
     if(!head1 || !head2)
          return head1;

     Node *ptr1 = head1;
     Node *ptr2 = head2;
     int count = 0;
     while(ptr1 && ptr2 && count < 5){
          ptr1 = ptr1->next;
          ptr2 = ptr2->next;
          count += 1;
     }

     ptr2->next = ptr1;
     return head2;
}

// O(s) space complexity good approach but it can be done using constant space
Node *intersection(Node *head1, Node *head2){
     if(!head1 || !head2)
          return NULL;

     Node *prev = NULL;

     stack<Node *> s1;
     stack<Node *> s2;

     while(head1){
          s1.push(head1);
          head1 = head1->next;
     }

     while(head2){
          s2.push(head2);
          head2 = head2->next;
     }

     while(s1.top() == s2.top()){
          prev = s1.top();
          s1.pop();
          s2.pop();
     }
     return prev;
}

int length(Node *head){
     if(!head)
          return 0;
     int count = 0;
     while(head){
          count += 1;
          head = head->next;
     }
     return count;
}

Node *find(Node *head1, Node *head2, int n){

     if(!head1 || !head2)
          return NULL;

     for(int i = 0; i < n; i++)
          head1 = head1->next;

     while(head1 && head2 && head1 != head2){
          head1 = head1->next;
          head2 = head2->next;
     }
     return head1;
}

// optimal intersection finding algo, constant space algorithm
Node *optimalIntersection(Node *head1, Node *head2){
     if(!head1 || !head2)
          return NULL;

     int n = length(head1);
     int m = length(head2);

     if(n > m)
          return find(head1,head2,n-m);
     return find(head2,head1,m-n);
}

// using sorting with O(N) space complexity
Node *intersectionSorting(Node *head1, Node *head2){
     if(!head1 || !head2)
          return NULL;
     int n = length(head1);
     Node *arr1[n];
     int i = 0;
     while(head1){
          arr1[i++] = &(*head1);
          head1 = head1->next;
     }
     Node *arr2[n];
     i = 0;
     while(head2){
          arr2[i++] = &(*head2);
          head2 = head2->next;
     }
     sort(arr1, arr1+n);
     sort(arr2, arr2+n);

     for(int i = 0; i < n; i++){
          std::cout << arr1[i] << " " << arr2[i] <<  " "  << arr1[i]->data  << " " << arr2[i]->data<< '\n';
          if(arr1[i] == arr2[i])
               return arr1[i];
     }
     return NULL;
}

int main(){
     Node *head1 = NULL;
     Node *head2 = NULL;

     while(true){
          int data;
          cin >> data;

          if(data == -1)
               break;
          head1 = insert(head1,data);
     }

     while(true){
          int data;
          cin >> data;

          if(data == -1)
               break;
          head2 = insert(head2,data);
     }

     makeIntersection(head1,head2);
     display(head1);
     display(head2);

     Node *node = intersectionSorting(head1,head2);
     if(node)
          std::cout << "intersection node : " << node->data << '\n';
     else
          std::cout << "no intersection" << '\n';

}

/*
               1 2 3 4 5 6 7 8 9 -1
               1 1 1 1 1 1 1 1 1 -1

*/
