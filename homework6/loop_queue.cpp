#include<stdio.h>
#include"loop_queue.h"
void init_loopqueue(loop_queue *q)
{
	q->front=0;
	q->rear=0;
}

bool is_empty(loop_queue *q)
{
	return q->front==q->rear;
}
bool is_full(loop_queue *q)
{
	return (q->rear+1)%MaxSize==q->front;
}
int get_length(loop_queue *q)
{
	return (q->rear-q->front+MaxSize)%MaxSize;
}
void insert_queue(loop_queue *q,elem_type value)
{
	if(!is_full(q))
	{
		q->data[q->rear]=value;
		q->rear=(q->rear+1)%MaxSize;

	}
}
void delete_queue(loop_queue *q,elem_type *e)
{
	if(!is_empty(q))
	{
		*e=q->data[q->front];
		q->front=(q->front+1)%MaxSize;
	}
}
int get_headval(loop_queue *q,elem_type *head)
{
	if(!is_empty(q))
	{
		return *head=q->data[q->front];
	}
	return NULL;
}
int get_tailval(loop_queue *q,elem_type *tail)
{
	if(!is_empty(q))
	{
		return *tail=q->data[q->rear-1];
	}
	return NULL;
}
void destory(loop_queue *q)
{
	while(!is_empty(q))
	{
		q->data[q->front]=0;
		q->front=(q->front+1)%MaxSize;
	}
}
void clear(loop_queue *q)
{
	for(int i=0;i<MaxSize;i++)
	{
		q->data[i]=0;
	}
	q-<front=0;
	q->rear=0;

}