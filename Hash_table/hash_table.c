#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define A_SIZE 10
//this is chaining

struct person{
  char name[50];
  int age;
  struct person* next;
};

struct person* hash_table[A_SIZE];

int hash_func(char* key){
  int number=0;
  for (int i=0;i<A_SIZE;i++){ 
    number+=key[i];

  }

  return number%A_SIZE;
}
void init_hash_table(){
  for (int i=0;i<A_SIZE;i++){
    hash_table[i]=NULL;
  }
}

bool hash_table_insert(struct person* p){
  if (p==NULL) return false;
  int index = hash_func(p->name);
  p->next =hash_table[index];
  hash_table[index]=p;
  return true;
}

struct person* hash_table_lookup(char* name){
  int index=hash_func(name);
  struct person* tmp=hash_table[index];
  while(tmp!=NULL && strcmp(tmp->name, name)!=0){
    tmp=tmp->next;
  }
  return tmp;
}

struct person* hash_table_delete(char* name){
  int index=hash_func(name);
  struct person* tmp=hash_table[index];
  struct person* prev=NULL;
  while(tmp!=NULL && strcmp(tmp->name, name)!=0){
    prev=tmp;
    tmp=tmp->next;
  }
  if(tmp==NULL) return NULL;
  if (prev ==NULL){
    hash_table[index]= tmp->next;
  }
  else{
    prev->next = tmp->next;
  }
  return tmp;
}


void print_table(){
  for (int i=0;i<A_SIZE;i++){
    if (hash_table[i]==NULL){
      printf("\t%i\t---\n",i);
    }
    else{
      printf("\t%i\t",i);
      struct person* tmp=hash_table[i];
      while(tmp!=NULL){
        printf("%s %d -",tmp->name,tmp->age);
        tmp=tmp->next;
      }
      printf("\n");
    }
  }
}

int main(){
  init_hash_table();
  print_table();
  struct person aaa={.name="aaa",.age=1};
  struct person bbb={.name="bbb",.age=2};
  struct person ccc={.name="ccc",.age=3};
  struct person caa={.name="caa",.age=4};
  struct person ddd={.name="ddd",.age=5};
  struct person eee={.name="eee",.age=6};

  hash_table_insert(&aaa);
  hash_table_insert(&bbb);
  hash_table_insert(&ccc);
  hash_table_insert(&caa);
  hash_table_insert(&ddd);
  hash_table_insert(&eee);

  printf("\n\n\n");
  print_table();
  return 0;
}