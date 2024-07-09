#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

//str must already be dynamically allocated
int push(ListNode** listRef, char* str)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = str;

	newNode->next = NULL;

	if ((*listRef) == NULL)
	{
		(*listRef) = newNode;
	}
	else
	{
		ListNode* p = *listRef;

        if (strcmp(p->data, str) == 0)
        {
            return 1;
        }

		while(p->next != NULL)
        {
            p = p->next;

            if (strcmp(p->data, str) == 0)
            {
                return 1;
            }
        }

		p->next = newNode;
	}

    return 0;
}

char* pop(ListNode** listRef)
{
	char* str = NULL;

	if (*listRef != NULL)
	{
		ListNode* rem = *listRef;
		str = rem->data;

		*listRef = (*listRef)->next;

		free(rem);
	}

	return str;
}

void freeList(ListNode** listRef)
{
	while (*listRef != NULL)
		free(pop(listRef));
}

void printList(ListNode* list)
{
	while(list != NULL)
	{
		printf("%s\n", list->data);
		list = list->next;
	}
}
