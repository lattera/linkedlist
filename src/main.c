#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "list.h"

void PrintList(LIST *list)
{
	unsigned int i;
	LISTNODE *node;
	
	i = 0;
	node = list->head;

	while ((node)) {
		printf("[*] node[%u]\n", i);
		printf("    sz:\t%lu\n", node->sz);
		printf("    data:\t%s\n",(char *) node->data);
		//printf("    data:\t%x\n",*(int *)(node->data));
		node = node->next; i++;
	}
}

int main(int argc, char *argv[])
{
	LISTNODE *target;
	LIST *list;
	int i;
	char *p;

	list = malloc(sizeof(LIST));
	memset(list, 0x00, sizeof(LIST));

	p="test1";
	AddNode(list, p, strlen(p)+1);

	p="test2";
	AddNode(list, p, strlen(p)+1);
	printf("list->head =\t%p\n", list->head);
	printf("list->teail =\t%p\n", list->tail);
	printf("list->head->next = \t%p\n", list->head->next);

	FreeList(list);

//	target = FindNodeByRef(list, list->tail->data);
//	DeleteNode(list, target);
//	target = FindNodeByRef(list, list->tail->data);
//	DeleteNode(list, target);

	free(list);
	return 0;
}
