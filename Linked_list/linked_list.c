#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"



// f. create node
struct node* create(int value){
  struct node* linked_list=malloc(sizeof(struct node));

  linked_list->value=value;
  linked_list->next=NULL;
  return linked_list;
}
// f. add
struct node* add(struct node* list,int value){
  struct node* item = create(value);
  item->next=list;
  return item;

}
// f. add_end 
struct node* add_end(struct node* list,int value){
  struct node* new_item = create(value);
  if (list==NULL){
    return new_item;
  }
  struct node* first = list;

  while(list->next !=NULL){
    list=list->next;
  }
  
  list->next=new_item;
  return first;

}
int search(struct node* list,int value){
  if (list==NULL){
    return -1;
  }
  struct node* first = list;
  
  while(list->next !=NULL){
    if(list->value==value){
      return 1;
    }
    list=list->next;
  }
  
  
  return -1;

}
//delete particular node //position not donw yet
struct node* del_pos(struct node* list,int pos){
  int i=0;
  struct node* first = list;

  if (pos==0){//working
    free(list);//delete O-th node
    list=list->next;
    return list;
  }

  while(list->next!=NULL){
    if (pos-1==i){
      free(list->next);
      list->next=(list->next->next);//jump over the pos_node
      
    }
    else{
      list=list->next;//new node
    }
    i++;
  }
  
  return first;

}

//delete whole l-list
void del_whole(struct node* list){
  if(list!=NULL){
    del_whole(list->next);
    free(list);
  }
}
//print list
void print(struct node* list){
  int i=0;
  for(struct node* this = list;this != NULL;this = this->next){
            printf("%d. value:%d\n",i,this->value);
            i++;
      }
      
}

///sec idea make static list of 100 int , i will indecate occupied pos
struct node* ll_qsort(struct node* list){
  int i=0;
  struct node* first = list;
  int* static_list;
  
  //dynamic append to darray of lenght i
  while(list->next!=NULL){
    list=list->next;
    i++;
  }
  static_list= (int*) calloc (i,sizeof(int));
  list=first;
  i=0;
  while(list->next!=NULL){
    static_list[i]=list->value;
    list=list->next;
    i++;
  }

  qsort (static_list, i, sizeof(int),compare);
  //hence i have sorted static list , now just go through linked list and change values
  list=first;
  i=0;
  while(list->next!=NULL){
    list->value = static_list[i];
    list=list->next;
    i++;
  }
  free(static_list);
  return first;
}

int compare (const void * a, const void * b){//need to be used in qsort
  return ( *(int*)a - *(int*)b );
}

int main(void) {
  struct node* list= NULL;
  print(list);
  list=add_end(list,8);
  list=add_end(list,1);
  list=add_end(list,7);
  list=add_end(list,3);
  list=add_end(list,33);
  list=add_end(list,83);

  print(list);

  list=del_pos(list,2);
  print(list);

  int s=search(list,9);
  printf("is in?: %d\n",s);

  


  //text of speed MY MERGE SORT VS QSORT
  clock_t t;
  t = clock();
  // code pass here
  list=ll_qsort(list);
  t = clock() - t;
  printf ("It took me %ld clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
  print(list);

  del_whole(list);
  print(list);

  return 0;
}

/*
https://student.kemt.fei.tuke.sk/predmety/pvjc/prednasky/linkedlist/linkedlist.c
*/