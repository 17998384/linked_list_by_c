
//	Created by 葛振东 on 2020/02/01.
//  Copyright  2020 葛振东. All rights reserved.

#include "linked_list_iterator.h"
#define TRUE 1
#define FALSE 0

int has_next(struct linked_list_iterator* iterator)
{
	if (iterator->size == 0)
	{
		return FALSE;
	}
	if (iterator->current >= iterator->list->size)
	{
		return FALSE;
	}
	return TRUE;
}

struct node* next(struct linked_list_iterator* iterator)
{
	struct node* node = iterator->head;
	if (iterator->size != iterator->list->size)
	{
		printf("并发修改异常!");
		delete_linked_list(iterator->list);
		exit(-2);
	}
	iterator->current++;
	iterator->head = node->next;
	return node;
}
