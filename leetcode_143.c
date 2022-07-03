#include <stdio.h>
#include <stdlib.h>

struct ListNode {
   int val;
   struct ListNode *next;
};

void insertAtBeginning(struct ListNode** head_ref, int new_data) {
  
  struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));

  new_node->val = new_data;

  new_node->next = (*head_ref);
  
  (*head_ref) = new_node;
}

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
/*
void reorderList(struct ListNode* head){
    if(!head||!head->next) return head;
    if(!head->next->next) return head;
    struct ListNode* ptr=head;
    int count=0;
    while(ptr){
        count++;
        ptr=ptr->next;
    }
    ptr=head;
    count=count/2+count%2;
    for (int i = 1; i < count; i++)
    {
        ptr=ptr->next;
    }
    struct ListNode* ptr2=ptr->next;
    ptr->next=NULL;
    ptr=ptr2;
    ptr2=ptr->next;
    struct ListNode* second=(struct ListNode*)malloc(sizeof(struct ListNode));
    second=NULL;
    while(ptr){
        insertAtBeginning(&second, ptr->val);
        free(ptr);
        ptr=ptr2;
        ptr2=ptr2->next;
    }
    
}
*/

void reorderList(struct ListNode* head){
    if(!head||!head->next) return;
    if(!head->next->next) return;
    int count=0;
    struct ListNode* ptr=head;
    while(ptr){
        count++;
        ptr=ptr->next;
    }
    count= count/2+count%2;
    ptr=head;
    struct ListNode* ptr2=ptr->next;
    for (int i = 1; i < count; i++)
    {
        ptr=ptr->next;
        ptr2=ptr2->next;
    }
    ptr->next=NULL;
    ptr=ptr2;
    ptr2=ptr2->next;
    struct ListNode* second=(struct ListNode*)malloc(sizeof(struct ListNode));
    second=NULL;
    while(ptr){
        insertAtBeginning(&second, ptr->val);
        free(ptr);
        ptr=ptr2;
        if(!ptr) break;
        ptr2=ptr2->next;
    }
    ptr=head;
    ptr2=second;
    struct ListNode* ptr3=NULL;
    while(ptr&&ptr2){
        ptr3=ptr->next;
        ptr->next=ptr2;
        ptr=ptr3;
        if(!ptr) break;
        ptr3=ptr2->next;
        ptr2->next=ptr;
        ptr2=ptr3;
        if(!ptr2) break;
    }

    return;
}

int main(){
    struct ListNode* one=NULL;
    for (int i = 1; i <= 5; i++)
    {
        insertAtEnd(&one, i);
    }
    printList(one);
    reorderList(one);
    printList(one);
    



    /*
    int count =5;
    count= count/2+count%2;
    struct ListNode* ptr=one;
    struct ListNode* ptr2=ptr->next;
    for (int i = 1; i < count; i++)
    {
        ptr=ptr->next;
        ptr2=ptr2->next;
    }
    ptr->next=NULL;
    ptr=ptr2;
    ptr2=ptr2->next;
    struct ListNode* second=NULL;
    
    while(ptr){
        insertAtBeginning(&second, ptr->val);
        free(ptr);
        ptr=ptr2;
        if(!ptr) break;
        ptr2=ptr2->next;
    }
    //printList(second);
    ptr=one;
    ptr2=second;
    struct ListNode* ptr3=NULL;
    while(ptr&&ptr2){
        ptr3=ptr->next;
        ptr->next=ptr2;
        //if(!ptr) break;
        ptr=ptr3;
        ptr3=ptr2->next;
        ptr2->next=ptr;
        ptr2=ptr3;
    }
    printList(one);
    //printf("%d\n", ptr->val);
    */

    return 0;
}