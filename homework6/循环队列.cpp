#include<stdio.h>
#include"loop_queue.h"

void main()
{
	loop_queue q;
	int e;
	init_loopqueue(&q);
	printf("%d\n",is_empty(&q));
	printf("%d\n",is_full(&q));
	//printf("%d\n",get_length(&q));//���Ԫ�ظ�������
	insert_queue(&q,10);//��Ӳ���
	insert_queue(&q,20);
	insert_queue(&q,30);
	insert_queue(&q,40);
	insert_queue(&q,50);
	int head;
	printf("%d\n",get_headval(&q,&head));//��ö�ͷԪ�ز���
	insert_queue(&q,60);
	printf("%d\n",get_tailval(&q,&head));
	delete_queue(&q,&e);//���Ӳ���
	insert_queue(&q,70);
	insert_queue(&q,80);
	insert_queue(&q,90);
	insert_queue(&q,100);
	insert_queue(&q,110);
	delete_queue(&q,&e);
	delete_queue(&q,&e);
	insert_queue(&q,11);
//	clear(&q);//��ն���
	destory(&q);//���ٶ��в���
	printf("%d\n",get_length(&q));




}