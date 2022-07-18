#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define R_NUM_MAX 100 // from 0 to R_NUM_MAX(MAX is not included)

struct node{
  int value;
  struct node* left;
  struct node* right;
};



void init_node(struct node* n){
  n->left=NULL;
  n->right=NULL;
}


struct node* create(int value){
  struct node* new_node=malloc(sizeof(struct node));
  init_node(new_node);
  new_node->value=value;
  return new_node;
}

struct node* insert(struct node* n,int value){
  struct node* new_node=create(value);
  if (n==NULL){//create root
    return new_node;
  }//insertion
  if(value<n->value){
    if(n->left==NULL){
      n->left=new_node;
    }
    free(new_node);
    insert(n->left, value);
  }

  else if(value>n->value){
    if(n->right==NULL){
      n->right=new_node;
    }
    free(new_node);
    insert(n->right, value);
  
    }
  return n;
}

int rnumb(){
  int x= -1*(rand() % R_NUM_MAX)+(R_NUM_MAX/2);
  //make range from -100 to 0 then shit by +50 so now it is from -50 to +50
  return x;
}

void printout(struct node* n){
  if (n!=NULL){
    if (n->left!=NULL){
      printout(n->left);
    }

    printf("%i\n",n->value);

    if (n->right!=NULL){
      printout(n->right);
    }
  }
  else{
    printf("Tree is EMPTY!\n");
  }
}

int search(struct node* n,int value){
  if(n->value==value){
    return 1;

  }
  else{
    if (n->left!=NULL && value<n->value){
      return search(n->left,value);
    }

    if (n->right!=NULL &&  value>n->value){
      return search(n->right,value);
    }
  }
  return -1;
}

int min(struct node* n){
  if (n->left !=NULL){
    return min(n->left);
  }
  return n->value;
}

int max(struct node* n){
  if (n->right !=NULL){
    return max(n->right);
  }
  return n->value;
}



int main(){
  struct node* root=NULL;
  printout(root);


  for(int i =0;i<10;i++){
    int r = rnumb();
    root=insert(root,r);
  }
  printout(root);
  printf("\n\n\n");
  printf("vysledok:%d\n \n",search(root, 4));
  printf("min:%d\n \n",min(root));
  printf("max:%d\n \n",max(root));
  
  return 0;
}
