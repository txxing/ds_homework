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
	coverse_mid(&s,str,arr);//中缀转后缀
	printf("中缀转后缀：  %s\n",arr);
	printf("后缀求值：    %d\n",get_val(&s,arr));

	/*	push(&s,11);//链栈入栈测试
	push(&s,12);
	push(&s,13);
	push(&s,14);
	printf("%d\n",is_empty(&s));//判断空
	int e;
	pop(&s,&e);//链栈出栈测试
	printf("%d\n",e);
	destory(&s);*///销毁测试
	
	//char *str="6 7 1 - 3 * + 8 2 / +";
	//printf("%d\n",get_val(&s,str));//后缀求值测试
	//char *str[]={"6","7","1","-","3","*","+","10","2","/","+"};
	//printf("%s\n",str[7]);
	//int len=sizeof(str)/sizeof(str[0]);
	//printf("%d\n",get_val(&s,str,len));//后缀求值测试
	//char *str="6 + ( 7 - 1 ) * 3 + 8 / 2";

}