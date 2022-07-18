#ifndef _DARRAY_H
#define _DARRAY_H

struct darray{
  int size;
  int* darray;
};


void Aprint(struct darray* num);
void add(struct darray* num,int num_to_add);
void create(struct darray* num, int* Array,int size);
void del(struct darray* num,int pos);
void insert(struct darray* num,int number_to_insert,int pos);
int size_of_darray(struct darray* num);
void sort(struct darray* num);
int compare (const void * a, const void * b);


#endif


