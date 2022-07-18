#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//this is an array version
#define STACK_SIZE 5

int Stack[STACK_SIZE];
int top=0;


bool push(int value){//addind to stack
	if (top>=STACK_SIZE){
		return false;
	}

	Stack[top]=value;
	top++;
	return true;
}

bool pop(){//removing LIFO
	if (top==0){//is empty
		return false;
	}
	top--;
	return true;
}

void printout(){
	for (int i=top-1;i>-1;i--){
		printf("%d\n",Stack[i]);
	}
}

int main(void) {
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  
  printout();
  printf("\n\n");
  pop();
  pop();
  printout();

  return 0;
}
