
//	Created by 葛振东 on 2020/02/01.
//  Copyright  2020 葛振东. All rights reserved.

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list_iterator.h"

/*
	链表bean
*/
struct linked_list
{
	int size;
	struct node* head;
	struct node* last;
};

/*
	node
*/
struct node
{
	char* value;
	struct node* next;
};

/*
	创建链表
*/
struct linked_list* new_linked_list();

/*
	add
*/
void* list_add(struct linked_list* list, char* value);

/*
	remove
*/
int list_remove(struct linked_list* list, char* value);

/*
	delete
*/
void delete_linked_list(struct linked_list* list);

/*
	iterator
*/
struct linked_list_iterator* iterator(struct linked_list* list);

/*
	链表初始化
*/
void list_prepare(struct linked_list* list);

/*
	创建node
*/
struct node* create_node(char* value);

/*
	释放node
*/
void free_node(struct node* node);

/*
	预处理
*/
void linked_list_iterator_preprare(struct linked_list_iterator* iterator, struct linked_list* list);