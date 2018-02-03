#include<stdlib.h>
#include<stdio.h>
#include"link_stack.h"

void init_linkstack(linkstack *s)
{
	s->top=NULL;
	s->count=0;
}
bool is_empty(linkstack *s)
{
	return s->count==0;
}
void push(linkstack *s,elem_type value)
{
	stacknode *newnode=(stacknode *)malloc(sizeof(stacknode));
	newnode->data=value;
	newnode->next=s->top;
	s->top=newnode;
	s->count++;
}
bool pop(linkstack *s,elem_type *e)
{
	if(is_empty(s))
	{
		return false;
	}
	*e=s->top->data;
	stacknode *q;
	q=s->top;
	s->top=s->top->next;
	free(q);
	s->count--;
	return true;
}

void destory(linkstack *s)
{
	stacknode *q;
	while(!is_empty(s))
	{
		q=s->top;
		s->top=s->top->next;
		s->count--;
		free(q);
	}
}


int get_val(linkstack *s,char *str)//��׺��ֵ
{
	int i=0;
	int m,n;
	int num;
	while(str[i]!='\0')
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			push(s,str[i]-'0');
		}
		else if(str[i]!=' ')
		{
			
			pop(s,&m);
			pop(s,&n);
		}
		switch(str[i])
		{
		case '+':push(s,n+m);
			break;
		case '-':push(s,n-m);
			break;
		case '*':push(s,n*m);
			break;
		case '/':push(s,n/m);
		}
		i++;
	}
	pop(s,&num);
	return num;
}
/*
int get_val(linkstack *s,char *str[],int l)//��׺��ֵ �д���9������
{
	int i=0;
	int m,n;
	int num;
	while(l!=0)
	{
		if(*str[i]=='+'||*str[i]=='-'||*str[i]=='*'||*str[i]=='/')
		{
		    pop(s,&m);
			pop(s,&n);
		}
		else 
		{
			int f=0;
			while(*str[i]!='\0')
			{
				f=f*10+(*str[i]-'0');
				str[i]++;
			}
			push(s,f);
		}
		switch(*str[i])
		{
		case '+':push(s,n+m);
			break;
		case '-':push(s,n-m);
			break;
		case '*':push(s,n*m);
			break;
		case '/':push(s,n/m);
		}
		l--;
		i++;
	}
	pop(s,&num);
	return num;
}*/

bool pop1(linkstack *s,char *e)
{
	if(is_empty(s))
	{
		return false;
	}
	*e=s->top->data;
	stacknode *q;
	q=s->top;
	s->top=s->top->next;
	free(q);
	s->count--;
	return true;
}
void push1(linkstack *s,char value)
{
	stacknode *newnode=(stacknode *)malloc(sizeof(stacknode));
	newnode->data=value;
	newnode->next=s->top;
	s->top=newnode;
	s->count++;
}
void coverse_mid(linkstack *s,char *str1,char *str2)
{
	int i=0,j=0;
	
	while(str1[i]!='\0')
	{
		char f='c';
		if(str1[i]>='0'&&str1[i]<='9')//���������뵽��׺���ʽ��
		{
			str2[j]=str1[i];
			j++;
		}
		else if(str1[i]=='{'||str1[i]=='['||str1[i]=='(')//��������ջ
		{
			push1(s,str1[i]);
		}
		else if(str1[i]=='}'||str1[i]==']'||str1[i]==')')//��������֮ǰ��ȫ����ջ
		{
			while(f!='('&&f!='{'&&f!='[')
			{
				pop1(s,&str2[j]);
				f=str2[j];
				j++;
			}
			j--;
			str2[j]=0;
		}
		else if(str1[i]!=' ')//�Ӽ��˳�
		{
			if(str1[i]=='+'||str1[i]=='-')//�������ڡ�+���͡�-�����ȼ���ȫ����ջ
			{
				while(f!='('&&f!='{'&&f!='[')//��������ֹͣ
			   {
				   if(is_empty(s))
				   {
					   break;
				   }
				   pop1(s,&str2[j]); 
				   f=str2[j];
				   if(f=='('||f=='{'||f=='[')
				   {
                       push1(s,f);
					   str2[j]=0;
					   j--;
				   } 
				   j++;
			   }
				push1(s,str1[i]);
			}
			else if(str1[i]=='*'||str1[i]=='/')//�������ڡ�*���͡�/�����ȼ���ȫ����ջ
			{
				while(f!='('&&f!='{'&&f!='['&&f!='+'&&f!='-')//�������Ż������ȼ������͵�ֹͣ��ջ
			   {
				   pop1(s,&str2[j]);
				   f=str2[j];
				   if(f=='('||f=='{'||f=='['||f=='+'||f=='-')
				   {
					   push1(s,f);
					   str2[j]=0;
					   j--;
				   }
				   j++;
			   }
				push1(s,str1[i]);
			}
		}
		i++;
	}
	while(!is_empty(s))//ȫ����ջ
	{
		pop1(s,&str2[j]);
		j++;
	}
	str2[j]=0;
}
