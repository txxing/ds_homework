#include<stdlib.h>
#include<stdio.h>
#include"link_stack.h"

#define IN 1;
#define OUT 0;

void init_linkstack(linkstack *s)
{
	s->top=NULL;
	s->count=0;
}
bool is_empty(linkstack *s)
{
	return s->count==0;
}
void push(linkstack *s,char value)
{
	stacknode *newnode=(stacknode *)malloc(sizeof(stacknode));
	newnode->data=value;
	newnode->next=s->top;
	s->top=newnode;
	s->count++;
}
bool pop(linkstack *s,char *e)
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
int get_top(linkstack *s)
{
	if(!is_empty(s))
	{
		return s->top->data;
	}
	return NULL;
}

int prior(char ch,int flag)
{
	if(flag==0)
	{
		switch(ch)
		{
		case '+' : return 2;
		case '-' : return 2;
		case '*' : return 4;
		case '/' : return 4;
	    case '(' : return 6;
		case ')' : return 1;
		}
	}
	else
	{
		switch(ch)
		{
		case '+': return 3;
		case '-': return 3;
		case '*': return 5;
		case '/': return 5;
	    case '(': return 1;
		}
	}
}
void coverse_mid_to_last(linkstack *s,char *mid,char *last)
{
	char f;
	while(*mid!='\0')
	{
		if(*mid>='0'&&*mid<='9')
		{
			*last=*mid;
			last++;
			mid++;
			*last=' ';
			last++;

		}
		else if(*mid==' ')
		{
			mid++;
		}
		else
		{
			if(is_empty(s))
			{
				push(s,*mid);
				mid++;
			}
			else
			{
				int pro_out=prior(*mid,0);
			    int pro_in=prior(get_top(s),1);
			    if(pro_out>pro_in)
			    {
				   push(s,*mid);
				   mid++;
			    }
				else if(pro_out<pro_in)
			    {
				   pop(s,last);
				   last++;
			    }
			    else
		    	{
			    	pop(s,&f);
					mid++;
				}
			
		    }
		}
	}
	while(!is_empty(s))
	{
		pop(s,last++);
	}
	*last='\0';
}