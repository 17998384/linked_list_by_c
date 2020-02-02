
//	Created by ���� on 2020/02/01.
//  Copyright  2020 ����. All rights reserved.


#define _CRT_SECURE_NO_WARNINGS
#include "linked_list.h"
#include "utils.h"

/*
	����10000���������Ƿ��ڴ�й©
*/
int test()
{
	struct linked_list* list = new_linked_list();
	for (int i = 0; i < 10000; i++)
	{
		char* value = (char*)malloc(sizeof(char) * 20);
		sprintf(value, "%s%d", "ceshi", i);
		list_add(list, value);
	}
	delete_linked_list(list);
}

int test1(void)
{
	struct linked_list* list = new_linked_list();
	char* value = (char*)malloc(sizeof(char) * 15);
	char* value1 = (char*)malloc(sizeof(char) * 15);
	strcpy(value, "��������");
	strcpy(value1, "��������1");
	list_add(list, value);
	list_add(list, value1);
	list_remove(list, value1);
	struct linked_list_iterator* iter = iterator(list);
	while (has_next(iter))
	{
		struct node* node = next(iter);
		printf("%s\n", node->value);
	}
	delete_linked_list(list);
}

int main(void)
{
	for (int i = 1; i <= 100000; i++)
	{
		printf("���ڲ��Ե�%d��.\n", i);
		test();
	}
	return 0;
}