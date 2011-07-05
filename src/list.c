#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "list.h"

LISTNODE *AddNode(LIST *list, void *data, unsigned long sz)
{
	LISTNODE *node;

	if (!(list))
		return NULL;

	if (!(list->nodes)) {
		list->nodes = malloc(sizeof(LISTNODE));
		if (!(list->nodes))
			return NULL;
		node = list->nodes;
	} else {
		node = list->nodes;
		while (node->next != NULL)
			node = node->next;
		node->next = malloc(sizeof(LISTNODE));

		if (!(node->next))
			return NULL;

		node = node->next;
	}
	memset(node, 0x00, sizeof(LISTNODE));

	node->data = malloc(sz);
	memset(node->data, 0x00, sz);
	node->sz = sz;
	memcpy(node->data, data, sz);

	return node;
}

void DeleteNode(LIST *list, LISTNODE *node)
{
	LISTNODE *del;

	if (!(list))
		return;

	if (node == list->nodes) {
		list->nodes = node->next;

		free(node->data);
		free(node);

		return;
	}

	del = list->nodes;
	while (del != NULL && del->next != node)
		del = del->next;

	if (!(del))
		return;

	del->next = del->next->next;
	
	free(node->data);
	free(node);
}

LISTNODE *FindNodeByRef(LIST *list, void *data)
{
	LISTNODE *node;

	if (!(list))
		return NULL;

	node = list->nodes;
	while ((node)) {
		if (node->data == data)
			return node;

		node = node->next;
	}

	return NULL;
}

LISTNODE *FindNodeByValue(LIST *list, void *data, unsigned long sz)
{
	LISTNODE *node;

	if (!(list))
		return NULL;

	node = list->nodes;
	while ((node)) {
		if (!memcmp(node->data, data, (sz > node->sz) ? node->sz : sz))
			return node;

		node = node->next;
	}

	return NULL;
}
