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
    調皮的辦法失敗了
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(k==0) return head;
    if(!head) return head;
    int count=0;
    struct ListNode* current=head;
    while(current){
        count++;
        current=current->next;
    }
    k=k%count;
    int i=0;
    current=head;
    while(current){
        current->val-=k;
        if(i<k) current->val +=count;
        i++;
        current=current->next;
    }

    return head;
}
*/

struct ListNode* rotateRight(struct ListNode* head, int k){
    if(k==0||!head) return head;
    struct ListNode* current=head;
    int count=0;
    while(current){
        count++;
        current=current->next;
    }
    current=head;
    k=count-k%count;
    while(k){
        insertAtEnd(&head, current->val);
        head=head->next;
        free(current);
        current=head;
        k--;
    }

    return head;
}

int main(){
    struct ListNode* one=NULL;
    for (int i = 0; i < 5; i++)
    {
        insertAtEnd(&one, i+1);
    }

    struct ListNode* two=NULL;
    insertAtEnd(&two, 0);
    insertAtEnd(&two, 1);
    insertAtEnd(&two, 2);
    
    struct ListNode* three=NULL;
    insertAtEnd(&three, 4);
    insertAtEnd(&three, 8);
    insertAtEnd(&three, -1);
    insertAtEnd(&three, 0);
    insertAtEnd(&three, 2);
    /*
    int count=0;
    
    while(current){
        count++;
        current=current->next;
    }

    printf("%d\n", count);
*/
    
    
    printList(one);
    printList(two);
    printList(three);
    printList(rotateRight(one, 2));
    printList(rotateRight(two, 4));
    printList(rotateRight(three, 13));
    
    return 0;
}