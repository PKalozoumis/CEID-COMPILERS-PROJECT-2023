#include <stdio.h>
#include <stdlib.h>

#include "hashing.h"

int hash(char* str)
{
    char c;
    int value = 0;

    while (c = *str)
    {
        value += c;
        str++;
    }

    return value % HASH_SIZE;
}

List* createHashTable()
{
    return (List*)calloc(HASH_SIZE, sizeof(List));
}

int insert(List* hashTable, char* str)
{
    return push(&(hashTable[hash(str)]), str);
}

void printHashTable(List* hashTable)
{
    for (int i = 0; i < HASH_SIZE; i++)
    {
        printf("%d\n----------\n", i);
        printList(hashTable[i]);
        printf("\n");
    }
}

void freeHashTable(List** hashTableRef)
{
    for (int i = 0; i < HASH_SIZE; i++)
        freeList(&((*hashTableRef)[i]));

    free(*hashTableRef);

}