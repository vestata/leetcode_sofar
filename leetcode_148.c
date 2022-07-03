#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
/*
void swap(struct ListNode *a, struct ListNode *b)
{
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}

void bubbleSort(struct ListNode *start){
    int swapped, i;
    struct ListNode *ptr1;
    struct ListNode *lptr = NULL;
  
    
    if (start == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->val > ptr1->next->val)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
*/

/*
struct ListNode *last_node(struct ListNode *head)
{
	struct ListNode *temp = head;
	while (temp != NULL && temp->next != NULL)
	{
		temp = temp->next;
	}
	return temp;
}

struct ListNode *parition(struct ListNode *first, struct ListNode *last)
{
	//Get first node of given linked list
	struct ListNode *pivot = first;
	struct ListNode *front = first;
	int temp = 0;
	while (front != NULL && front != last)
	{
		if (front->val < last->val)
		{
			pivot = first;
			//Swap node value
			temp = first->val;
			first->val = front->val;
			front->val = temp;
			//Visit to next node
			first = first->next;
		}
		//Visit to next node
		front = front->next;
	}
	//Change last node value to current node
	temp = first->val;
	first->val = last->val;
	last->val = temp;
	return pivot;
}

void quick_sort(struct ListNode *first, struct ListNode *last)
{
	if (first == last)
	{
		return;
	}
	struct ListNode *pivot = parition(first, last);
	if (pivot != NULL && pivot->next != NULL)
	{
		quick_sort(pivot->next, last);
	}
	if (pivot != NULL && first != pivot)
	{
		quick_sort(first, pivot);
	}
}
*/

struct ListNode* sortedMerge(struct ListNode* a, struct ListNode* b)
{
    // base cases
    if (a == NULL) {
        return b;
    }
 
    else if (b == NULL) {
        return a;
    }
 
    struct ListNode* result = NULL;
 
    // pick either `a` or `b`, and recur
    if (a->val <= b->val)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
 
    return result;
}

void frontBackSplit(struct ListNode* source, struct ListNode** frontRef,
                    struct ListNode** backRef)
{
    // if the length is less than 2, handle it separately
    if (source == NULL || source->next == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }
 
    struct ListNode* slow = source;
    struct ListNode* fast = source->next;
 
    // advance `fast` two nodes, and advance `slow` one node
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    // `slow` is before the midpoint in the list, so split it in two
    // at that point.
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void MERgesort(struct ListNode** head)
{
    // base case — length 0 or 1
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
 
    struct ListNode* a;
    struct ListNode* b;
 
    // split `head` into `a` and `b` sublists
    frontBackSplit(*head, &a, &b);
 
    // recursively sort the sublists
    MERgesort(&a);
    MERgesort(&b);
 
    // answer = merge the two sorted lists
    *head = sortedMerge(a, b);
}

struct ListNode* sortList(struct ListNode* head)
{
    MERgesort(&head);
    return head;
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

void printlinkedlist(struct ListNode *p){
  while (p!=NULL)
  {
    printf("%d\t", p->val);
    p=p->next;
  }
}

int main(){
    struct ListNode *one=NULL;
    insertAtEnd(&one, 4);
    insertAtEnd(&one, 2);
    insertAtEnd(&one, 1);
    insertAtEnd(&one, 3);
    struct ListNode *two=NULL;
    insertAtEnd(&two, -1);
    insertAtEnd(&two, 5);
    insertAtEnd(&two, 3);
    insertAtEnd(&two, 4);
    insertAtEnd(&two, 0);
    printlinkedlist(one);
    printf("\n");
    sortList(one);
    printlinkedlist(one);
    printf("\n");
    printlinkedlist(two);
    printf("\n");
    sortList(two);
    printlinkedlist(two);
    return 0;
}