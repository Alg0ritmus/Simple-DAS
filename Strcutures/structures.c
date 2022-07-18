#include <stdio.h>
#include <string.h>
#include "structures.h"
//import strcutures.h

void print_struct(struct test Patrik);//ak nechcem pouzit hodnoty pouzi variant bez *
void change_age(struct test* Patrik);// ak menim hodnotu premennej pouzivam variant s *


int main(){
	struct test Patrik; //deklaration of structure || we created structure called Patrik
	memset(&Patrik,0,sizeof(struct test)); //init struct to avoid troubles with memory

	//to access attributes from struct test use operator "." or "->"
	strcpy(Patrik.meno,"Patrik");
	strcpy(Patrik.priezvisko,"Zelenak");
	Patrik.vek = 20;
	Patrik.vaha= 88.6;

	////////////////////////////////////////

	change_age(&Patrik);
  print_struct(Patrik);

  struct test Names[2];//init list of structures
  memset(&Names,0,sizeof(struct test) * 2);//alocate them
  print_struct(Names[1]);//print 

  strcpy(Names[1].meno,"Patrik");//access to name
  print_struct(Names[1]);

	return 0;
	}


void print_struct(struct test Patrik){
  printf("Name: %s, Surname: %s, Age: %d, weight: %f\n",Patrik.meno,Patrik.priezvisko,Patrik.vek,Patrik.vaha);
}

void change_age(struct test* Patrik){
  (Patrik->vek) += 10;
}