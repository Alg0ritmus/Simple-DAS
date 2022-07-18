#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

struct node{
  int value;
  struct node* next;
};


struct node* create(int value);// needed to create node || return empty node

struct node* add(struct node* list,int value);
struct node* add_end(struct node* list,int value);
int search(struct node* list,int value);// return 1 is value is in list or -1 if not
struct node* del_pos(struct node* list,int pos); //del node on particular pos
void del_whole(struct node* list);//del whole list recursively
void print(struct node* list);// print whole list with indexes in rows
struct node* ll_qsort(struct node* list);
int compare (const void * a, const void * b);//need to be due to qsort()

#endif 