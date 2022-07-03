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

struct ListNode* swapNodes(struct ListNode* head, int k){
    struct ListNode* ptr=head;
    struct ListNode* ptr2=head;
    int count=0;
    if(!head||!head->next) return head;
    if(!head->next->next && k==2){
        ptr2=ptr2->next;
        count=ptr->val;
        ptr->val=ptr2->val;
        ptr2->val=count;
        return head;
    }
    count=0;
    while(ptr){
        count++;
        ptr=ptr->next;
    }
    ptr=head;
    ptr2=head;
    //這是正常時候
    for (int i = 1; i < k; i++)
    {
        ptr=ptr->next;
    }
    for (int i = 0; i < count-k; i++)
    {
        ptr2=ptr2->next;
    }
    count=ptr->val;
    ptr->val=ptr2->val;
    ptr2->val=count;

    return head;
}

int main(){
    
    struct ListNode* one=NULL;
    insertAtEnd(&one,1);
    insertAtEnd(&one,2);
    insertAtEnd(&one,3);
    insertAtEnd(&one,4);
    insertAtEnd(&one,5);
    printList(one);
    printList(swapNodes(one, 5));
    

    struct ListNode* two=NULL;
    insertAtEnd(&two, 7);
    insertAtEnd(&two, 9);
    insertAtEnd(&two, 6);
    insertAtEnd(&two, 6);
    insertAtEnd(&two, 7);
    insertAtEnd(&two, 8);
    insertAtEnd(&two, 3);
    insertAtEnd(&two, 0);
    insertAtEnd(&two, 9);
    insertAtEnd(&two, 5);
    printList(two);
    printList(swapNodes(two, 10));
    /*
    struct ListNode* ptr=two;
    int count=0;
    while(ptr){
        count++;
        ptr=ptr->next;
    }
    printf("%d\n", count);
    ptr=two;
    for (int i = 1; i < 5; i++)
    {
        ptr=ptr->next;
    }
    printf("%d\n", ptr->val);
    struct ListNode* ptr2=two;
    for (int i = 1; i < count-5+1; i++)
    {
        ptr2=ptr2->next;
    }
    printf("%d\n", ptr2->val);
    */
   /*
   struct ListNode* three=NULL;
   insertAtEnd(&three, 100);
   insertAtEnd(&three, 99);
   printList(three);
   printList(swapNodes(three, 2));
   */
    return 0;
}