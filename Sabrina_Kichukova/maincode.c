include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
  
}nodeDeque;

void pushFirst(nodeDeque** head, int data){
nodeDeque* node = malloc(sizeof(nodeDeque));
if(!node){
     fprintf(stderr,"Error! Problem with memory allocation!");
     exit(-1);
}
node->data = data;
node->next = *head;
node->prev = NULL;
if(*head != NULL){
    (*head)-> prev = node;
}
*head = node;
}

void pushBack(nodeDeque** head, int data){
nodeDeque* node = malloc(sizeof(nodeDeque));
if(!node){
     fprintf(stderr,"Error! Problem with memory allocation!");
     exit(-1);
}
node->data = data;
node->next = NULL;
(*head)->next = node;
node->prev = (*head);
}

void printDeque(nodeDeque* head){
nodeDeque* current = head;

while (current != NULL)
{
    printf("%d\n",current->data);
    current = current->next;
}
putchar('\n');

}
void popFirst(nodeDeque** head){
    if (*head == NULL){
        return;
    }
    *head = (*head)->next;
    free((*head));
}

int main(void){

nodeDeque* head = NULL;
pushFirst(&head, 5);
popFirst(&head);
pushFirst(&head, 6);
pushFirst(&head, 7);
//pushBack(&head,8);
printDeque(head);

return 0;

}
