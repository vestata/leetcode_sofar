#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct pair{
    int value;
    int key;
    struct pair *next;
};

void display(struct pair ar[], int size){
    printf("Value\tKey\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t%d\n", ar[i].value, ar[i].key); //輸出slot的 value 跟key
        struct pair *ptr;//新增一個pointer
        ptr=ar[i].next;//將pointer指向hash table slot 的next(預設為NULL)
        while (ptr!=NULL)
        {
            printf("%d\t", ptr->value);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

void search(struct pair ar[], int size){
    int se;
    printf("Enter the element you want to search:");
    scanf("%d", &se);
    if (ar[se%size].value==se)
    {
        printf("Element在%d\n", se%size);
    }else{
        printf("Element doesn't exist\n");
    }
}

void insert(struct pair ar[], int size){
    int inp;
    printf("Enter the element to insert: ");
    scanf("%d", &inp);
    if(ar[inp%size].value==-1)
        ar[inp%size].value=inp;
    else{
        struct pair *kvpair;
        kvpair =(struct pair *)malloc(sizeof(struct pair *));
        kvpair->value=inp;
        kvpair->next=NULL;
        ar[inp%size].next=kvpair;
    }
}

int main(){
    int tmp, j, size, a;
    printf("Enter table size: ");
    scanf("%d", &size); //輸入hash table大小
    struct pair hash_table[size]; //建立一個大小size的hash table
    while (a<size)
    {
        hash_table[a].next= NULL ;a++; //將所有slot 的 pointer 清為0
    }
    a=0;
    while (a<size)
    {
        hash_table[a].value= -1 ;a++; ////將所有slot 的值清為-1
    }
    printf("Enter:");
    for (int i = 0; i < size; i++)
    {
        /*scanf("%d", &tmp);
        hash_table[tmp%size].value=tmp;
        hash_table[tmp%size].key=tmp%size;*/

        insert(hash_table, size);
    } //輸入要存入得值並放進相對應的slot
    printf("\n");
    display(hash_table, size); //輸出hashtable
    /*
    insert(hash_table, size);
    display(hash_table, size);
    */
    return 0;
}