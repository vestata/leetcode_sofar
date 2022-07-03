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

//若是middle有兩個的時候選前面的
struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
//若是middle有兩個的時候選後面的
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *slow=head, *fast=head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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