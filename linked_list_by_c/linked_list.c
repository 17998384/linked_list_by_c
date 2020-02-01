

//	Created by ¸ğÕñ¶« on 2020/02/01.
//  Copyright  2020 ¸ğÕñ¶«. All rights reserved.

#include "linked_list.h"
#define TRUE 1
#define FALSE 0

struct linked_list* new_linked_list()
{
	struct linked_list* list = (struct linked_list*)malloc(sizeof(struct linked_list));
	check_malloc_memory(list);
	//³õÊ¼»¯
	list_prepare(list);
	return list;
}

void* list_add(struct linked_list* list, char* value)
{
	struct node* new_node = create_node(value);
	if (list->size == 0)
	{
		list->head = new_node;
		list->last = new_node;
		list->size++;
		return value;
	}
	list->last->next = new_node;
	list->last = new_node;
	list->size++;
	return value;
}

int list_remove(struct linked_list* list, char* value)
{
	if (list->size == 0)
	{
		return FALSE;
	}
	struct node* prev = NULL;
	struct node* node = list->head;
	do
	{
		if (check_node_value(node->value, value))
		{
			if (prev == NULL)
			{
				list->head = node->next;
				free_node(node);
				list->size--;
				return TRUE;
			}
			prev->next = node->next;
			if (check_node_value(list->last->value, value))
			{
				list->last = prev;
			}
			free(node);
			list->size--;
			return TRUE;
		}
	} while ((node = (prev = node)->next) != NULL);
	return FALSE;
}

void delete_linked_list(struct linked_list* list)
{
	if (list == NULL || list->size == 0)
	{
		return;
	}
	if (list->size == 1)
	{
		free_node(list->head);
		free(list);
		return;
	}
	struct node* prev;
	struct node* node = list->head;
	while ((node = (prev = node)->next) != NULL)
	{
		free_node(prev);
	}
	free_node(prev);
	free(list);
}

struct linked_list_iterator* iterator(struct linked_list* list)
{
	struct linked_list_iterator* iterator = (struct linked_list_iterator*)malloc(sizeof(struct linked_list_iterator));
	linked_list_iterator_preprare(iterator, list);
	return iterator;
}

void list_prepare(struct linked_list* list)
{
	list->size = 0;
	list->head = NULL;
	list->last = NULL;
}

struct node* create_node(char* value)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	check_malloc_memory(node);
	node->value = value;
	node->next = NULL;
	return node;
}

int check_node_value(char* node_value, char* value)
{
	return node_value == NULL ? value == NULL : !(strcmp(node_value, value));
}

void free_node(struct node* node)
{
	free(node->value);
	free(node);
}

void linked_list_iterator_preprare(struct linked_list_iterator* iterator, struct linked_list* list)
{
	iterator->current = 0;
	iterator->size = list->size;
	iterator->list = list;
	iterator->head = list->head;
}