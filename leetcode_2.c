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
/*
struct ListNode *newNode(int data)
{
    struct ListNode *NewNode = (struct ListNode *) malloc(sizeof(struct ListNode));
    NewNode->val = data;
    NewNode->next = NULL;
    return NewNode;
}
*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(!l1)return l2;
    if(!l2)return l1;
    struct ListNode *current=NULL;
    int v1,v2,carry=0,temp;
    while(l1||l2){
        v1=l1?l1->val:0;
        v2=l2?l2->val:0;
        temp=v1+v2+carry;
        if(temp>=10){
            temp%=10;
            carry=1;
        }
        else{
            carry=0;
        }
        insertAtEnd(&current, temp);
        if(l1)l1=l1->next;
        if(l2)l2=l2->next;
    }
    if(carry==1){
        insertAtEnd(&current, 1);
    }
    return current;
}

void printList(struct ListNode* node) {
  while (node != NULL) {
  printf(" %d ", node->val);
  node = node->next;
  }
  printf("\n");
}

int main(){
    int l1[]={2,4,3};
    int l2[]={5,6,4};
    struct ListNode* head1=NULL;
    struct ListNode* head2=NULL;
    
    insertAtEnd(&head1, 2);
    insertAtEnd(&head1, 4);
    insertAtEnd(&head1, 3);
    insertAtEnd(&head2, 5);
    insertAtEnd(&head2, 6);
    insertAtEnd(&head2, 4);

    struct ListNode* ex1=NULL;
    struct ListNode* ex2=NULL;
    for (int i = 0; i < 7; i++)
    {
        insertAtEnd(&ex1, 9);
    }
    for (int i = 0; i < 4; i++)
    {
        insertAtEnd(&ex2, 9);
    }
    
    
    /*
    struct ListNode* head1=NULL;
    struct ListNode* head2=NULL;
    
    arrtolinkedlist(l1, head1);
    arrtolinkedlist(l2, head2);
    */
   /*
    printList(head1);
    printList(head2);
    printList(addTwoNumbers(head1, head2));
    */

   printList(ex1);
   printList(ex2);
   printList(addTwoNumbers(ex1, ex2));
 
    return 0;
}