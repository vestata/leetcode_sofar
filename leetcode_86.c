#include <stdio.h>
#include <stdlib.h>

struct ListNode {
   int val;
   struct ListNode *next;
};

void insertAtEnd(struct ListNode** head_ref, int new_data) {
  struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
  struct ListNode* last = *head_ref; /* used in step 5*/

  new_node->val = new_data;
  new_node->next = NULL;

  if (*head_ref == NULL) {
  *head_ref = new_node;
  return;
  }

  while (last->next != NULL) last = last->next;

  last->next = new_node;
  return;
}

void printList(struct ListNode* node) {
  while (node != NULL) {
  printf(" %d ", node->val);
  node = node->next;
  }
  printf("\n");
}

struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode* ptr1=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* ptr2=(struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode* cur1=ptr1;
    struct ListNode* cur2=ptr2;

    while(head){
        if(head->val<x){
            cur1->next=head;
            cur1=head;
        }else{
            cur2->next=head;
            cur2=head;
        }
        head=head->next;
    }
    cur2->next=NULL;
    cur1->next=ptr2->next;
    return ptr1->next;
}

int main(){
    struct ListNode* one=NULL;
    
    insertAtEnd(&one, 1);
    insertAtEnd(&one, 4);
    insertAtEnd(&one, 3);
    insertAtEnd(&one, 2);
    insertAtEnd(&one, 5);
    insertAtEnd(&one, 2);
    
    printList(one);
    printList(partition(one, 3));

    struct ListNode* two=NULL;
    insertAtEnd(&two, 2);
    insertAtEnd(&two, 1);

    printList(two);
    printList(partition(two, 2));

    return 0;
}