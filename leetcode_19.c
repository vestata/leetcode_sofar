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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(n==0) return head;
    if(!head) return head;
    if(!head->next&&n==1) return NULL; 
    struct ListNode* ptr=head;
    int count=0;
    while(ptr){
        count++;
        ptr=ptr->next;
    }
    if(count==n){
        head=head->next;
        return head;
    }
    count-=n;
    ptr=head;
    for (int i = 1; i < count; i++)
    {
        ptr=ptr->next;
    }
    ptr->next=ptr->next->next;
    
    return head;
}

int main(){
    struct ListNode* one=NULL;
    for (int i = 1; i <= 5; i++)
    {
        insertAtEnd(&one, i);
    }
    printList(one);

    struct ListNode* two=NULL;
    insertAtEnd(&two, 1);

    struct ListNode* three=NULL;
    insertAtEnd(&three, 1);
    insertAtEnd(&three, 2);

    printList(removeNthFromEnd(one, 2));
    printList(removeNthFromEnd(two, 1));
    printList(removeNthFromEnd(three, 2));
    return 0;
}