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

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;
    struct ListNode* cur = head;
    
    if (cur == NULL) return NULL;
    
    next = head->next;
    
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* ans=NULL;
    l1=reverse(l1);
    l2=reverse(l2);
    int v1, v2, carry=0, temp;
    while(l1||l2){
        v1=l1?l1->val:0;
        v2=l2?l2->val:0;
        temp=v1+v2+carry;
        if(temp>=10){
            temp%=10;
            carry=1;
        }else{
            carry=0;
        }
        insertAtBeginning(&ans, temp);
        if(l1) l1=l1->next;
        if(l2) l2=l2->next;
    }
    if(carry==1){
        insertAtBeginning(&ans, 1);
    }
    return ans;
}

int main(){
    struct ListNode* l1=NULL;
    struct ListNode* l2=NULL;
    insertAtEnd(&l1, 7);
    insertAtEnd(&l1, 2);
    insertAtEnd(&l1, 4);
    insertAtEnd(&l1, 3);
    insertAtEnd(&l2, 5);
    insertAtEnd(&l2, 6);
    insertAtEnd(&l2, 4);
    printList(addTwoNumbers(l1, l2));


    return 0;
}