#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isPalindrome(struct ListNode* head){
  /*
  struct ListNode* current=head->next;
  if(head==NULL) return head;
  while(current!=NULL){
    current->val=current->val^head->val;
    head=head->next;
    current=current->next;
  }
  if(head->val==0){
    return 1;
  }else{
    return 0;
  }*/

  struct ListNode* tmp=head;
  int n=0;
  while(tmp!=NULL){
    n++;
    tmp=tmp->next;
  }

  int arr[n];
  int i=0;
  tmp=head;
  while(tmp!=NULL){
    arr[i]=tmp->val;
    i++;
    tmp=tmp->next;
  }
  for (int j = 0; j < n; j++)
  {
    if(arr[j]!=arr[n-1]) return 0;
    n--;
  }
  return 1;
}

void printList(struct ListNode* node) {
  while (node != NULL) {
  printf(" %d ", node->val);
  node = node->next;
  }
}

int main(){
    struct ListNode* one=NULL;
    insertAtEnd(&one, 1);
    insertAtEnd(&one, 2);
    insertAtEnd(&one, 2);
    insertAtEnd(&one, 1);
    printList(one);
    printf("\n");
    printf("%d\n", isPalindrome(one));

    struct ListNode* two=NULL;
    insertAtEnd(&two, 1);
    insertAtEnd(&two, 2);
    printf("%d\n", isPalindrome(two));

    struct ListNode* three=NULL;
    insertAtEnd(&three, 1);
    insertAtEnd(&three, 3);
    insertAtEnd(&three, 0);
    insertAtEnd(&three, 2);
    printList(three);
    printf("\n");
    printf("%d\n", isPalindrome(three));
    return 0;
}