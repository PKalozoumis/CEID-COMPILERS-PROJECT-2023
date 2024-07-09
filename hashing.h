#ifndef HASHING_H
#define HASHING_H

#include "list.h"

#define HASH_SIZE 101

int hash(char* str);
List* createHashTable();
int insert(List* hashTable, char* str);
void printHashTable(List* hashTable);
void freeHashTable(List** hashTableRef);

#endif