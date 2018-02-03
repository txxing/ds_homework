#include"loop_list.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>

void intit_list(loop_list *phead)
{
	phead->data=0;
	phead->next=phead;
}

int get_length(loop_list *phead)
{
	int len=0;
	loop_list *p=phead;
	while(p->next!=phead)
	{
		p=p->next;
		len++;
	}
	return len;
}

bool insert_pos(loop_list *phead,int pos,int value)
{
	assert(phead!=NULL);
	if(pos<=0||pos>get_length(phead)+1)
	{
		return false;
	}
	loop_list *newnode=(loop_list *)malloc(sizeof(loop_list)*1);
	newnode->data=value;
	loop_list *p=phead;
	while(pos--!=1)
	{
		p=p->next;
	}
	newnode->next=p->next;
	p->next=newnode;
	return true;
}

bool delete_val(loop_list *phead,int value)
{
	assert(phead!=NULL);
	loop_list *p=phead;
	loop_list *q;
	while(p->next!=NULL)
	{
		if(p->next->data==value)
		{
			q=p->next;
			p->next=p->next->next;
			free(q);
			return true;
		}
	    p=p->next;
	}
	return false;
}

loop_list *joseph_problem(loop_list *phead)
{
	assert(phead!=NULL);
	loop_list *p=phead;
	if(phead->next==phead)
	{
		return NULL;
	}
	while(phead->next->next!=phead)
	{
		for(int i=0;i<2;i++)
		{
			if(p->next==phead)
			{
				p=p->next;
			}
			p=p->next;
		}
		if(p->next==phead)
		{
			p=p->next;
		}
	    delete_val(phead,p->next->data);
	}
	loop_list *pp=phead->next;
	return pp;
}
void showloop_list(loop_list *phead)
{
	assert(phead!=NULL);
	loop_list *p=phead;
	while(p->next!=phead)
	{
		p=p->next;
		printf("%d  ",p->data);
	}
}

