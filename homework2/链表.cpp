#include<stdio.h>
#include"linklist.h"

void main()
{
	node phead;
	node newnode;
	init_list(&phead);//初始化测试
	//头插尾插测试
	insert_head(&phead,55);
	insert_head(&phead,44);
	insert_head(&phead,33);
	insert_head(&phead,22);
	insert_head(&phead,11);
	insert_tail(&phead,66);
	insert_tail(&phead,77);
	printf("%d\n",get_length(&phead));//获得长度测试
	show_list(&phead);//打印测试
	delete_val(&phead,33);//删除结点测试
	//show_list(&phead);
  get_val(&phead,44,&newnode);//根据值获得结点测试
	printf("%d\n",newnode.data);
	delete_head(&phead);//删除头结点测试
//	show_list(&phead);
    delete_tail(&phead);//删除尾结点测试
	//show_list(&phead);
   delete_pos(&phead,3);//根据位置删除结点
   //show_list(&phead);
   insert_pos(&phead,2,33);//根据位置插入节点测试
   //show_list(&phead);
   get_pos(&phead,2,&newnode);//根据位置获得节点测试
  // printf("%d\n",newnode.data);
   destory_list(&phead);//销毁链表测试
   show_list(&phead);

}