#include<stdio.h>
#include<string.h>
#include"link_stack.h"


void main()
{
	linkstack s;
	init_linkstack(&s);

	char *str="6 + { ( 7 - 1 )  * 3 + 8 } / 2";
	printf("%s\n",str);
	char arr[30]={0};
	coverse_mid(&s,str,arr);//��׺ת��׺
	printf("��׺ת��׺��  %s\n",arr);
	printf("��׺��ֵ��    %d\n",get_val(&s,arr));

	/*	push(&s,11);//��ջ��ջ����
	push(&s,12);
	push(&s,13);
	push(&s,14);
	printf("%d\n",is_empty(&s));//�жϿ�
	int e;
	pop(&s,&e);//��ջ��ջ����
	printf("%d\n",e);
	destory(&s);*///���ٲ���
	
	//char *str="6 7 1 - 3 * + 8 2 / +";
	//printf("%d\n",get_val(&s,str));//��׺��ֵ����
	//char *str[]={"6","7","1","-","3","*","+","10","2","/","+"};
	//printf("%s\n",str[7]);
	//int len=sizeof(str)/sizeof(str[0]);
	//printf("%d\n",get_val(&s,str,len));//��׺��ֵ����
	//char *str="6 + ( 7 - 1 ) * 3 + 8 / 2";

}