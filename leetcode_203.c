#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

void insertAtEnd(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref; /* used in step 5*/

  new_node->data = new_data;
  new_node->next = NULL;

  if (*head_ref == NULL) {
  *head_ref = new_node;
  return;
  }

  while (last->next != NULL) last = last->next;

  last->next = new_node;
  return;
}

void printList(struct Node* node) {
  while (node != NULL) {
  printf(" %d ", node->data);
  node = node->next;
  }
}

struct Node* removeElements(struct Node* head, int val){
  struct Node* current=head;
  if(head==NULL) return head;
  while(current!=NULL){
    if(current->next==NULL) break;
    if(current->next->data==val){
      current->next=current->next->next;
    }else{
      current=current->next;
    }
  }
  if(head->data==val){
    current=head;
    head=head->next;
    free(current);
  }
  return head;
}

int main(){
  struct Node* one=NULL;
  insertAtEnd(&one, 6);
  insertAtEnd(&one, 1);
  insertAtEnd(&one, 2);
  insertAtEnd(&one, 6);
  insertAtEnd(&one, 3);
  insertAtEnd(&one, 4);
  insertAtEnd(&one, 5);
  insertAtEnd(&one, 6);
  removeElements(one, 6);
  printList(one);
  printf("\n");

  struct Node* two=NULL;
  insertAtEnd(&two, 7);
  insertAtEnd(&two, 7);
  insertAtEnd(&two, 7);
  insertAtEnd(&two, 7);
  removeElements(two, 7);
  printList(two);
  return 0;
}