#include<stdio.h>
#include"linklist.h"

void main()
{
	node phead;
	node newnode;
	init_list(&phead);//��ʼ������
	//ͷ��β�����
	insert_head(&phead,55);
	insert_head(&phead,44);
	insert_head(&phead,33);
	insert_head(&phead,22);
	insert_head(&phead,11);
	insert_tail(&phead,66);
	insert_tail(&phead,77);
	printf("%d\n",get_length(&phead));//��ó��Ȳ���
	show_list(&phead);//��ӡ����
	delete_val(&phead,33);//ɾ��������
	//show_list(&phead);
  get_val(&phead,44,&newnode);//����ֵ��ý�����
	printf("%d\n",newnode.data);
	delete_head(&phead);//ɾ��ͷ������
//	show_list(&phead);
    delete_tail(&phead);//ɾ��β������
	//show_list(&phead);
   delete_pos(&phead,3);//����λ��ɾ�����
   //show_list(&phead);
   insert_pos(&phead,2,33);//����λ�ò���ڵ����
   //show_list(&phead);
   get_pos(&phead,2,&newnode);//����λ�û�ýڵ����
  // printf("%d\n",newnode.data);
   destory_list(&phead);//�����������
   show_list(&phead);

}