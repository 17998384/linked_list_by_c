#include "utils.h"
/*
	����ڴ��Ƿ�����ɹ�
*/
void check_malloc_memory(void* point)
{
	if (point == NULL)
	{
		printf("�ڴ�����ʧ��!\n");
		exit(-2);
	}
}