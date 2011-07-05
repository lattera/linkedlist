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
	node = list->nodes;

	while ((node)) {
		printf("[*] node[%u]\n", i);
		printf("    sz:\t%u\n", node->sz);
		printf("    data:\t%s\n", node->data);
		node = node->next; i++;
	}
}

int main(int argc, char *argv[])
{
	char *p;
	LIST *list;

	list = malloc(sizeof(LIST));
	memset(list, 0x00, sizeof(LIST));

	p = "This is a test";
	AddNode(list, p, strlen(p)+1);
	p = "Random cows happen to randomly moo randomly";
	AddNode(list, p, strlen(p)+1);

	PrintList(list);

	return 0;
}
