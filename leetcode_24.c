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
struct ListNode* swapPairs(struct ListNode* head){
    if(!head || !head->next) return head;
    struct ListNode* prev=head;
    struct ListNode* temp=head;
    struct ListNode* current=head->next;
    while (current||prev)
    {
        if(prev->next==NULL) break;
        temp->next=current;
        prev->next=current->next;
        current->next=prev;
        prev=prev->next;
        current=prev->next;
    }
    return head;
}
*/
struct ListNode* swapPairs(struct ListNode* head){
    if(!head||!head->next)return head;
    
    if(!head->next->next){
        struct ListNode *ptr=head;
        head=ptr->next;
        ptr->next->next=ptr;
        ptr->next=NULL;
        return head;
    }
    
    struct ListNode *ptr=head,*ptr2=head->next->next;
    head=ptr->next;
    ptr->next=ptr2;
    head->next=ptr;
    while(ptr2->next){
        ptr2=ptr2->next;
        ptr->next->next=ptr2->next;
        ptr2->next=ptr->next;
        ptr->next=ptr2;
        ptr=ptr2->next;
        if(ptr->next){
            ptr2=ptr->next;
        }else{
            return head;
        }
    }
    return head;
}

int main(){
    struct ListNode* head1=NULL;
    insertAtEnd(&head1, 1);
    insertAtEnd(&head1, 2);
    insertAtEnd(&head1, 3);
    insertAtEnd(&head1, 4);
    struct ListNode* head2=NULL;
    struct ListNode* head3=NULL;
    insertAtEnd(&head3, 1);

    printList(head1);
    printList(head2);
    printList(head3);
    printList(swapPairs(head1));
    printList(swapPairs(head2));
    printList(swapPairs(head3));
    return 0;
}
