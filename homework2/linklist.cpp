#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

void init_list(node *phead)
{
	phead->data=0;
	phead->next=NULL;
}
bool is_empty(node *phead)
{
	if(phead->next==NULL)
	{
		return true;
	}
	return false;
}
int get_length(node *phead)
{
	int len=0;//不算头结点
	node *p=phead;
	while(p->next!=NULL)
	{
		len++;
		p=p->next;
	}
	return len;
}
void insert_head(node *phead,ELEM_TYPE value)
{
	node *newnode=(node *)malloc(sizeof(node));
	newnode->data=value;
	newnode->next=phead->next;
	phead->next=newnode;
}
void insert_tail(node *phead,ELEM_TYPE value)
{
	node *newnode=(node *)malloc(sizeof(node));
	newnode->data=value;
	newnode->next=NULL;
	node *p=phead;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=newnode;
}
void destory_list(node *phead)
{
	node *p=phead;
	node *q=p->next;
	while(q->next!=NULL)
	{
		p->next=q->next;
		free(q);
		q=p->next;
	}
	p->next=q->next;
}
void show_list(node *phead)
{
	node *p=phead;
	while(p->next!=NULL)
	{
		p=p->next;
		printf("%d\n",p->data);
	}
}
bool delete_val(node *phead,ELEM_TYPE value)
{
	node *p=phead;
	node *q;
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
node *get_val(node *phead,ELEM_TYPE value,node *newnode)
{
	node *p=phead;
	//node *newnode=(node *)malloc(sizeof(node))
	while(p->next!=NULL)
	{
		if(p->next->data==value)
		{
			newnode->data=p->next->data;
			newnode->next=p->next->next;
			return newnode;
		}
		p=p->next;
	}
	return NULL;
}
bool delete_head(node *phead)
{
	node *q;
	if(phead->next!=NULL)
	{
		q=phead->next;
		phead->next=phead->next->next;
		free(q);
		return true;
	}
	return false;
}
bool delete_tail(node *phead)
{
	node *p=phead;
	node *q;
	if(phead->next!=NULL)
	{
		while(p->next->next!=NULL)
	    {
	     	p=p->next;
	    }
		q=p->next;
		p->next=NULL;
	    free(q);
	    return true;
	}
	return false;
}
bool delete_pos(node *phead,int pos)
{
	if(pos<0||pos>get_length(phead))
	{
		return false;
	}
	node *p=phead;
	node *q;
	if(phead->next!=NULL)
	{
		while(pos!=1)
	    {
		  pos--;
		  p=p->next;
		}
		q=p->next;
	    p->next=p->next->next;
	    free(q);
		return true;
	}
	return false;
}
bool insert_pos(node *phead,int pos,ELEM_TYPE value)
{
	node *p=phead;
	if(pos<0||pos>get_length(phead))
	{
		return false;
	}
	node *newnode=(node *)malloc(sizeof(node));
	newnode->data=value;
	while(pos!=1)
	{
		pos--;
		p=p->next;
	}
	newnode->next=p->next;
	p->next=newnode;
	return true;
}
node *get_pos(node *phead,int pos,node *newnode)
{
	if(pos<0||pos>get_length(phead))
	{
		return NULL;
	}
	node *p=phead;
	while(pos!=1)
	{
		p=p->next;
		pos--;
	}
	newnode->data=p->next->data;
	newnode->next=p->next->next;
	return newnode;
}