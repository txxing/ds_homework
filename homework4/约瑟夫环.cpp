#include<stdio.h>
#include"loop_list.h"

void main()
{
	loop_list phead;
	intit_list(&phead);//��ʼ��
	for(int i=1;i<=10;i++)
	{
		insert_pos(&phead,i,i);//�������
	}
	//showloop_list(&phead);

	//printf("%d\n",get_length(&phead));
    //delete_val(&phead,4);
    joseph_problem(&phead);//Լɪ������
	showloop_list(&phead);//��ӡ����
}
