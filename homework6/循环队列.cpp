#include<stdio.h>
#include"loop_queue.h"

void main()
{
	loop_queue q;
	int e;
	init_loopqueue(&q);
	printf("%d\n",is_empty(&q));
	printf("%d\n",is_full(&q));
	//printf("%d\n",get_length(&q));//获得元素个数测试
	insert_queue(&q,10);//入队测试
	insert_queue(&q,20);
	insert_queue(&q,30);
	insert_queue(&q,40);
	insert_queue(&q,50);
	int head;
	printf("%d\n",get_headval(&q,&head));//获得队头元素测试
	insert_queue(&q,60);
	printf("%d\n",get_tailval(&q,&head));
	delete_queue(&q,&e);//出队测试
	insert_queue(&q,70);
	insert_queue(&q,80);
	insert_queue(&q,90);
	insert_queue(&q,100);
	insert_queue(&q,110);
	delete_queue(&q,&e);
	delete_queue(&q,&e);
	insert_queue(&q,11);
//	clear(&q);//清空队列
	destory(&q);//销毁队列测试
	printf("%d\n",get_length(&q));




}