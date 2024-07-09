#ifndef LIST_H
#define LIST_H
    
typedef struct ListNode
{
    struct ListNode* next;
    char* data;
}
ListNode;

typedef ListNode* List;

int push(ListNode** listRef, char* str);
char* pop(ListNode** listRef);
void search(ListNode* list, char* str);
void freeList(ListNode** listRef);
void printList(ListNode* list);

#endif