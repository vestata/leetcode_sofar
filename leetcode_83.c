#include <stdio.h>
#include <stdlib.h>

//remove duplicate num from sorted list
//已經存在一個single linked list

struct Node{
    int data;
    struct Node *next;
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

struct Node* deleteDuplicates(struct Node* head){
    if(head==NULL||head->next==NULL) return head;
    struct Node *current=head;
    while (current!=NULL)
    {
        if(current->next==NULL) break;
        if (current->data==current->next->data)
        {
            current->next=current->next->next;
            //free(current->next);
        }else{
            current=current->next;
        }
    }
    return head;
}

void printList(struct Node* node) {
  while (node != NULL) {
  printf(" %d ", node->data);
  node = node->next;
  }
}

int main(){
    struct Node *head=NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    deleteDuplicates(head);
    printList(head);
}