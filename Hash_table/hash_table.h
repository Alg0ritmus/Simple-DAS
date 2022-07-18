#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

struct person{
  char name[50];
  int age;
  struct person* next;
};

struct person* hash_table[A_SIZE];


int hash_func(char* key);
void init_hash_table();
bool hash_table_insert(struct person* p);
struct person* hash_table_lookup(char* name);
struct person* hash_table_delete(char* name);
void print_table();
#endif