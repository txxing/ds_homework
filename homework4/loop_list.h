


typedef struct list_Node
{
	int data;
	struct list_Node *next;
}loop_list;

void intit_list(loop_list *phead);
int get_length(loop_list *phead);
bool insert_pos(loop_list *phead,int pos,int value);
bool delete_val(loop_list *head,int value);
loop_list *joseph_problem(loop_list *phead);
void showloop_list(loop_list *phead);

