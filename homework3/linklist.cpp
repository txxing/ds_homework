#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"linklist.h"

void init_list(node *phead)
{
	assert(phead!=NULL);
	phead->data=0;
	phead->next=NULL;
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
bool insert_pos(node *phead,int pos,ELEM_TYPE value)
{
	node *p=phead;
	if(pos<0||pos>get_length(phead)+1)
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
void show_list(node *phead)
{
	node *p=phead;
	while(p->next!=NULL)
	{
		p=p->next;
		printf("%d\n",p->data);
	}
}
void reverse_show(node *phead)
{
	static node *p=phead;
	node *q;
    if(p!=NULL)
	{
		if(p->next!=NULL)
		{
			p=p->next;
			q=p;
			reverse_show(p);
			printf("%d\n",q->data); 
		}
	}
}
bool delete_address(node *phead,node *ph)
{
	node *q=phead;
	if(phead==NULL||ph==NULL)
	{
		return false;
	}
	if(ph->next!=NULL)//一般情况
	{
		q=ph->next;
		ph->data=ph->next->data;
		ph->next=ph->next->next;
		free(q);
		return true;
	}
	else if(ph->next==NULL)//删除尾结点
	{
		node *p=phead;
		while(p->next!=ph)
		{
			p=p->next;
		}
		p->next=NULL;
		free(ph);
		return true;
	}
}
int get_kval(node *phead,int k)
{
	node *p=phead->next;
	node *q=phead;
	if(k<=0||phead==NULL)
	{
		return NULL;
	}
	while(k!=0)
	{
		if(q->next!=NULL)
		{
         	q=q->next;
		}
		else
		{
			return NULL;
		}
		k--;
	
	}
	while(q->next!=NULL)
	{
		p=p->next;
		q=q->next;
	}
	return p->data;
}
node *reverse_list(node *phead)
{
	node *p=phead;
	node *prev=NULL;
	node *reverse=NULL;
	while(p!=NULL)
	{
		node *pnext=p->next;
		if(pnext==NULL)
		{
			reverse=p;
		}
		p->next=prev;
		prev=p;
		p=pnext;

	}
	return reverse;	
}
node *merge(node *phead1,node *phead2)
{
	if(phead1==NULL)
	{
		return phead2;
	}
	if(phead2==NULL)
	{
		return phead1;
	}
	node *p=phead1->next;
	node *q=phead2->next;
	node *phead3=phead1;
	node *w=phead3;
	while(p!=NULL&&q!=NULL)
	{

		if(p->data > q->data)
		{
			w->next=q;
			q=q->next;
		}
		else
		{
			w->next=p;
			p=p->next;
		}
		w=w->next;
	}
	if(p==NULL)
	{
		w->next=q;
	}
	else
	{
		w->next=p;
	}
	return phead3;
}
node *findsame(node *phead1,node *phead2)
{
	assert(phead1!=NULL);
	assert(phead2!=NULL);
	node *p=phead1->next;
	node *q=phead2->next;
	int len1=get_length(phead1);
	int len2=get_length(phead2);
	if(len1>=len2)
	{
		int l=len1-len2;
		while(l!=0)
		{
			p=p->next;
			l--;
		}
	}
	else
	{
		int l=len2-len1;
		while(l!=0)
		{
			q=q->next;
			l--;
		}
	}
	while(p->data!=q->data)
	{
		if(p==NULL||q==NULL)
		{
			return NULL;
		}
		p=p->next;
		q=q->next;
	}
	node *newnode=(node *)malloc(sizeof(node));
	newnode->data=p->data;
	newnode->next=p->next;
	return newnode;
}

node *copy(node *phead)
{
	node *ph=phead;
	node *p=phead->next;
	int len=get_length(ph);
	for(int i=1;i<=len;i++)
	{
		insert_pos(ph,2*i,p->data);
		p=p->next->next;
	}
	return ph;
}
