#include<stdio.h>

typedef int ELEM_TYPE;
typedef struct l_node
{
	ELEM_TYPE data;
	struct l_node *next;
}node;

void init_list(node *phead);
bool is_empty(node *phead);
int get_length(node *phead);
void insert_head(node *phead,ELEM_TYPE value);
void insert_tail(node *phead,ELEM_TYPE value);
void destory_list(node *phead);
void show_list(node *phead);
bool delete_val(node *phead,ELEM_TYPE value);
node *get_val(node *phead,ELEM_TYPE value,node *newnode);
bool delete_head(node *phead);
bool delete_tail(node *phead);
bool delete_pos(node *phead,int pos);
bool insert_pos(node *phead,int pos,ELEM_TYPE value);
node *get_pos(node *phead,int pos,node *newnode);