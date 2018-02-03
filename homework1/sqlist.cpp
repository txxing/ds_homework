#include<stdio.h>
#include<stdlib.h>
#include"sqlist.h"

void init_sqlist(sqlist *p)//��ʼ��˳���
{
	p->elem=(elemtype *)malloc(sizeof(elemtype)*init_Size);
	p->len=0;
	p->length=init_Size;
}
void destroy_sqlist(sqlist *p)//���ٶ���˳���
{
	free(p->elem);
	p->elem=NULL;
	p->len=0;
	p->length=0;
}
void clear_sqlist(sqlist *p)//����˳���
{
	p->len=0;
}
bool is_empty(sqlist *p)//�ж�˳����Ƿ�Ϊ��
{
	if(p->len==0)
	{
		return true;
	}
	return false;

}
int get_length(sqlist *p)//���˳�����
{
	return p->len;
}
bool insert(sqlist *p,int pos,elemtype val)//����λ����˳����в���Ԫ��
{
	if(pos<0||pos>p->len)
	{
		return false;
	}
	if(p->len==p->length)
	{
		inc(p);

	}
	for(int i=p->len-1;i>=pos;i--)
	{
		p->elem[i+1]=p->elem[i];
	}
	p->elem[pos]=val;
	p->len++;
	return true;
}
void inc(sqlist *p)//����˳���ÿ����������
{
	p->elem=(elemtype *)realloc(p->elem,(p->length+2)*sizeof(elemtype));
	p->length+=2;
}
bool delete_value(sqlist *p,elemtype val)//����������ɾ�����е�Ԫ��
{
	for(int i=0;i<p->len;i++)
	{
		if(p->elem[i]==val)
		{
			for(int j=i;j<p->len;j++)
			{
				p->elem[j]=p->elem[j+1];
			}
			p->len--;
			return true;
		}
	}
	return false;

}
bool delete_pos(sqlist *p,elemtype pos)//����λ��ɾ��˳����е�Ԫ��
{
	if(pos>0&&pos<p->len)
	{
		for(int i=pos-1;i<p->len;i++)
	   {
		   p->elem[i]=p->elem[i+1];
	    }
	    p->len--;
	   return true; 
	}
	return false;
}
int search(sqlist *p,elemtype key)//���ز��ҵ���Ԫ�ص�λ��
{
	for(int i=0;i<p->len;i++)
	{
		if(p->elem[i]==key)
		{
			return i+1;
		}
	}
	return -1;
}
void show(sqlist *p)//��ӡ˳���
{
	for(int i=0;i<p->len;i++)
	{
		printf("%d   ",p->elem[i]);
	}
	printf("\n");
}
bool get_elem(sqlist *p,int pos,elemtype *e)//��˳����е�pos��λ�õ�Ԫ�ط��ظ�e
{
	if(pos>0&&pos<p->len)
	{
		*e=p->elem[pos-1];
		return true;
	}
	return false;
}