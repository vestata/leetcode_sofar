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

/*
//這超級慢
struct ListNode* oddEvenList(struct ListNode* head){
    if(!head||!head->next) return head;
    struct ListNode*ptr1, *ptr2;
    struct ListNode *even=(struct ListNode*)malloc(sizeof(struct ListNode));
    even=NULL;
    ptr1=head;
    ptr2=ptr1->next;
    while(ptr1){
        if(!ptr2) break;
        insertAtEnd(&even, ptr2->val);
        ptr1->next=ptr2->next;
        free(ptr2);
        if(!ptr1->next) break;
        ptr1=ptr1->next;
        ptr2=ptr1->next;
    }
    ptr1->next=even;

    return head;
}
*/

struct ListNode* oddEvenList(struct ListNode* head){
    if(!head||!head->next) return head;
    struct ListNode* odd=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* even=(struct ListNode*)malloc(sizeof(struct ListNode));
    int i=1;
    struct ListNode *ptr1, *ptr2;
    ptr1=odd;
    ptr2=even;
    while(head){
        if(i%2==1){
            ptr1->next=head;
            ptr1=ptr1->next;
        }else{
            ptr2->next=head;
            ptr2=ptr2->next;
        }
        head=head->next;
    }
    ptr1->next=NULL;
    ptr2->next=NULL;
    ptr1->next=even->next;


    return odd->next;
}


int main(){
    struct ListNode* one=NULL;
    for (int i = 1; i <= 5; i++)
    {
        insertAtEnd(&one, i);
    }
    printList(one);
    printList(oddEvenList(one));

    struct ListNode* two=NULL;
    insertAtEnd(&two, 2);
    insertAtEnd(&two, 1);
    insertAtEnd(&two, 3);
    insertAtEnd(&two, 5);
    insertAtEnd(&two, 6);
    insertAtEnd(&two, 4);
    insertAtEnd(&two, 7);
    printList(two);
    printList(oddEvenList(two));

    return 0;
}