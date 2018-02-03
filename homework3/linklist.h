#include<stdio.h>
typedef int ELEM_TYPE;

typedef struct l_node
{
	ELEM_TYPE data;
	struct l_node *next;
}node;
typedef struct ComplexlistNode 

void init_list(node *phead); 
int get_length(node *phead);
void show_list(node *phead);
bool insert_pos(node *phead,int pos,ELEM_TYPE value);
void reverse_show(node *phead);
bool delete_address(node *phead,node *ph);
int get_kval(node *phead,int k);
node *reverse_list(node *phead);
node *merge(node *phead1,node *phead2);
node *findsame(node *phead1,node *phead2);
node *copy(node *phead);