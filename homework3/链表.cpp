#include<stdio.h>
#include"linklist.h"

void main()
{
	node phead;
	init_list(&phead);
	for(int i=1;i<=8;i++)
	{
		 insert_pos(&phead,i,i*11);
	}
   // show_list(&phead);
	node phead1;
	init_list(&phead1);
	
	//show_list(&phead1);
	node phead2;
	init_list(&phead2);
	
	for(int i=1;i<=8;i++)
	{
		 insert_pos(&phead1,i,i*2);

	}
	insert_pos(&phead2,1,3);
	insert_pos(&phead2,2,5);
	insert_pos(&phead2,3,10);
	insert_pos(&phead2,4,12);
	insert_pos(&phead2,5,14);
	insert_pos(&phead2,6,16);
/*
	for(int i=1;i<=5;i++)
	{
		 insert_pos(&phead2,i,i*3);
	}*/

	
	//show_list(&phead2);


	
    //reverse_show(&phead);//�����ӡ
	//show_list(&phead);
	//delete_address(&phead,phead.next);//ɾ��λ�ýڵ�O��1����û�����꣩
//	printf("%d\n",get_kval(&phead,3));//��ӡ������k���ڵ��ֵ
	
	//reverse_list(&phead);//��ӡ��ת����
	//show_list(merge(&phead1,&phead2));//˳��ϲ�����
  //  printf("%d\n",findsame(&phead1,&phead2)->data);//�ҵ�һ��������㣻
		



}