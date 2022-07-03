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

struct ListNode* middleNode(struct ListNode* head){
    if(!head||!head->next) return head;
    if(!head->next->next) return head->next;
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    int count=0;
    while(slow){
        count++;
        slow=slow->next;
    }
    slow=head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(count%2==0){
        slow=slow->next;
    }
    return slow;
}

int main(){
    struct ListNode*one=NULL;
    for (int i = 0; i < 5; i++)
    {
        insertAtEnd(&one, i+1);
    }
    printList(one);
    printList(middleNode(one));

    struct ListNode*two=NULL;
    for (int i = 0; i < 6; i++)
    {
        insertAtEnd(&two, i+1);
    }
    printList(two);
    printList(middleNode(two));
    
}