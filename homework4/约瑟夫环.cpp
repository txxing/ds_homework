#include<stdio.h>
#include"loop_list.h"

void main()
{
	loop_list phead;
	intit_list(&phead);//初始化
	for(int i=1;i<=10;i++)
	{
		insert_pos(&phead,i,i);//插入测试
	}
	//showloop_list(&phead);

	//printf("%d\n",get_length(&phead));
    //delete_val(&phead,4);
    joseph_problem(&phead);//约瑟夫环问题
	showloop_list(&phead);//打印测试
}
