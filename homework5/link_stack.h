
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
void push(linkstack *s,elem_type value);
bool pop(linkstack *s,elem_type *e);
void destory(linkstack *s);
int get_val(linkstack *s,char *str);
//int get_val(linkstack *s,char *str[],int l);
void coverse_mid(linkstack *s,char *str1,char *str2);
void push2(linkstack *s,char value);
bool pop1(linkstack *s,char *e);
