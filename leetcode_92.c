#include <stdio.h>
#include <stdlib.h>

struct ListNode {
   int val;
   struct ListNode *next;
};

void insertAtBeginning(struct ListNode** head_ref, int new_data) {
  // Allocate memory to a node
  struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));

  // insert the data
  new_node->val = new_data;

  new_node->next = (*head_ref);

  // Move head to new node
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

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
  if(!head||!head->next) return head;
  if(left==right) return head;
  
  struct ListNode *p, *q, *cur;
  struct ListNode *hhead=(struct ListNode *)malloc(sizeof(struct ListNode));
  hhead->next=head;
  p=hhead;
  for (int i = 1; i < left; i++)
  {
    p=p->next;
  }
  cur=p->next;
  for (int i = left; i < right; i++)
  {
    q=cur->next;
    cur->next=q->next;
    q->next=p->next;
    p->next=q;
  }
  
  return hhead->next;
}

int main(){
  struct ListNode* one=NULL;
  insertAtEnd(&one, 1);
  
  insertAtEnd(&one, 2);
  insertAtEnd(&one, 3);
  insertAtEnd(&one, 4);
  
  insertAtEnd(&one, 5);
  printList(one);
  printList(reverseBetween(one, 2, 4));

  return 0;
}