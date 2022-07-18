#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct node{
  int value;
  struct node* next;
};

struct queue{
    struct node *head;//pointer to some node
    struct node *tail;//pointer to some node
};

void initialize(struct queue *q){
    q->head = NULL;
    q->tail = NULL;
}

void insert(struct queue* q, int value){
  struct node* new_node=malloc(sizeof(struct node));
  new_node->value=value;
  new_node->next = NULL;

  if (q->tail!=NULL){
    q->tail->next = new_node; //q->tail points to last added node q->tail->next set next of last added node to point
    q->tail = new_node;
  }
  else{
    q->head = q->tail = new_node;
  }

}

void pop(struct queue* queue){
  struct queue* temp = malloc(sizeof(queue));
  temp->head=queue->head;
  queue->head=queue->head->next;
  free(temp);
}

bool display(struct node *node)
{
    if(node == NULL)
    {
        return false;
    }
    else
    {
        printf("%d\n", node -> value);
        display(node->next);
    }
    return true;
}



int main(void) {
  struct queue* queue=malloc(sizeof(queue));
  initialize(queue);
  insert(queue, 1);
  insert(queue, 2);
  insert(queue, 3);
  insert(queue, 4);
  display(queue->head);
  printf("\n\n\n");
  pop(queue);
  insert(queue, 5);
  pop(queue);
  display(queue->head);


  return 0;
}