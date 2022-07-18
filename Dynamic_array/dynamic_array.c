#include <stdio.h>
#include <string.h>
#include "dynamic_array.h"
#include <stdlib.h>


int main(){
  //crate array
  struct darray num;
  struct darray zoznam;
  num.size=0;//need to be zero just tu init default the size
  zoznam.size=0;
  int Array[]={1,2,3};
  create(&num,Array,3);//create darray from static array syntax: create(struct darray [name],[static array / NULL],size of array), if array is set to NULL size of array can be random but "0" is prefered
  create(&zoznam,NULL,10);
  
  add(&num,99); // syntax: add(&nane_of_darray,number to add)
  add(&num,990);
  del(&num,0);//syntax: del(&name_of_darray,index to delete)
  insert(&num, 88, 1);// syntax: insert(&name_of_darray,number,position)

  Aprint(&num);

  printf("size:%d",size_of_darray(&num));


  

  return 0;
}


void Aprint(struct darray* num){
  int size = num->size;
  printf("[");
  for(int i=0;i<size;i++){
    printf("%d ",num->darray[i]);
  }
  printf("]");
  printf("\n");
}

void add(struct darray* num,int num_to_add){
  //allocate new array
  int* new_array;
  int size_of_array = num->size;
  new_array = (int*) calloc (size_of_array,sizeof(int));

  //copy to new array
  for(int i=0;i<size_of_array;i++){
   new_array[i]=num->darray[i];
  }
  // free old array
  free(num->darray);

  //rewrite new array to num.darray
  /*allocate new darray*/
  num->size+=1;//new size of darray
  num->darray= (int*) calloc (size_of_array,sizeof(int));

  for(int i=0;i<size_of_array;i++){
    num->darray[i]=new_array[i];
  }
  num->darray[size_of_array]= num_to_add ;
}

void create(struct darray* num, int* Array,int size){
  if (Array==NULL){
    num->size=0;
    num->darray= (int*) calloc (0,sizeof(int));
  }
  else{
    num->size=size;
    //free(num->darray);
    num->darray= (int*) calloc (size,sizeof(int));
    for(int i=0;i<size;i++){
      num->darray[i]=Array[i];
      
    }
  }
}

void del(struct darray* num,int pos){
  //allocate new array
  int* new_array;
  num->size-=1;//new size of darray
  int size_of_array = num->size;
  new_array = (int*) calloc (size_of_array,sizeof(int));

  //copy to new array
  int index=0;
  for(int i=0;i<size_of_array+1;i++){//treba rozsitir o 1 kvoli tomu ze nacitavam zo stareho zoznamu
    if(i!=pos){
      new_array[index]=num->darray[i];
      index+=1;
    }
   
  }
  // free old array
  free(num->darray);

  //rewrite new array to num.darray
  /*allocate new darray*/
  
  num->darray= (int*) calloc (size_of_array,sizeof(int));

  for(int i=0;i<size_of_array;i++){
    num->darray[i]=new_array[i];
  }
}


void insert(struct darray* num,int number_to_insert,int pos){
  //check if pos is propper
  
  if (pos>num->size || pos<0){
    printf("Error: Insertion was cancelled due to invalid insorting position.");
    return;}
  //allocate new array
  int* new_array;
  num->size+=1;//new size of darray
  int size_of_array = num->size;
  new_array = (int*) calloc (size_of_array,sizeof(int));

  //copy to new array + insert new number
  int index=0;
  for(int i=0;i<size_of_array;i++){
    if(i!=pos){
      new_array[i]=num->darray[index];
      index+=1;
    }
    else{
      new_array[i]=number_to_insert;
    }
   
  }

  // free old array
  free(num->darray);

  //rewrite new array to num.darray
  /*allocate new darray*/
  
  num->darray= (int*) calloc (size_of_array,sizeof(int));

  for(int i=0;i<size_of_array;i++){
    num->darray[i]=new_array[i];
  }
}

int size_of_darray(struct darray* num){
  return num->size;
}

void sort(struct darray* num){
  
  qsort (num->darray, num->size, sizeof(int),compare);
}

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}