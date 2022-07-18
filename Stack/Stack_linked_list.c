#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack{
  int value;
  struct Stack* next;
};

struct Stack* create(int value){
  struct Stack* node=malloc(sizeof(struct Stack));

  node->value=value;
  node->next=NULL;
  return node;
  
}

struct Stack* append(struct Stack* node,int value){
  struct Stack* first=create(value);
  first->next=node;
  return first;
}

struct Stack* pop(struct Stack* node){
  struct Stack* list= node->next;
  free(node);
  return list;
}

void printout(struct Stack* stack){
  for(struct Stack* this = stack;this != NULL;this = this->next){
    printf("%d\n",this->value);
  }
}

int main(void) {
  struct Stack* stack=NULL;
  stack=append(stack, 1);
  stack=append(stack, 2);
  stack=append(stack, 3);
  stack=append(stack, 4);
  stack=append(stack, 5);
  printout(stack);
  printf("\n");
  stack=pop(stack);
  stack=pop(stack);
  stack=pop(stack);
  printout(stack);

  return 0;
}
