#pragma once
#include "linked_list.h"

struct linked_list_iterator
{
	int current;
	int size;
	struct node* head;
	struct linked_list* list;
};

/*
	hasNext
*/
int has_next(struct linked_list_iterator* iterator);

/*
	next
*/
struct node* next(struct linked_list_iterator* iterator);