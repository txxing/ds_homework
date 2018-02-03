
typedef int elem_type;
typedef struct StackNode
{
	elem_type data;
	struct StackNode *next;
}stacknode;
typedef struct LinkStack
{
	stacknode *top;
	int count;

}linkstack;

void init_linkstack(linkstack *s);
bool is_empty(linkstack *s);
void push(linkstack *s,char value);
bool pop(linkstack *s,char *e);
void destory(linkstack *s);
int get_val(linkstack *s,char *str);
void coverse_mid_to_last(linkstack *s,char *mid,char *last);
int get_top(linkstack *s);