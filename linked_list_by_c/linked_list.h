
//	Created by ���� on 2020/02/01.
//  Copyright  2020 ����. All rights reserved.

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list_iterator.h"

/*
	����bean
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
	��������
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
	�����ʼ��
*/
void list_prepare(struct linked_list* list);

/*
	����node
*/
struct node* create_node(char* value);

/*
	�ͷ�node
*/
void free_node(struct node* node);

/*
	Ԥ����
*/
void linked_list_iterator_preprare(struct linked_list_iterator* iterator, struct linked_list* list);