#include <stdio.h>
#include <string.h>

#include <stdlib.h>


struct dynamic{
  int* array;
  int lenght;
};

void init(struct dynamic* array){
  array->lenght=0;
  array->array=NULL;
}

struct dynamic* append(struct dynamic* array,int value){
  array->lenght+=1;
  array->array=realloc(array->array,array->lenght*(sizeof(int)));
  array->array[array->lenght-1]=value;
  return array;
} 

void printout(struct dynamic* array){
  for (int i=0;i<array->lenght;i++){
    printf("%d\n",array->array[i]);
  }
}

int main(){
  //crate array
  struct dynamic* arr=NULL;
  //init(arr);

  arr=append(arr,1);
  arr=append(arr,3);
  arr=append(arr,5);
  arr=append(arr,7);
  arr=append(arr,9);
  printout(arr);
  return 0;
}

