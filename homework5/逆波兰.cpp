#include<stdio.h>
#include<string.h>
#include"link_stack.h"


void main()
{
	linkstack s;
	init_linkstack(&s);

	char *mid="6 + ( 7 - 1 )  * 3 + 8  / 2";
	char last[30];
	coverse_mid_to_last(&s,mid,last);//��׺ת��׺
	printf("��׺ת��׺��  %s\n",last);
	//printf("��׺��ֵ��    %d\n",get_val(&s,last));
}