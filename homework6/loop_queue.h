
#define MaxSize 11
typedef int elem_type;
typedef struct Loop_Queue
{
	elem_type data[MaxSize];
	int front;
	int rear;
	
}loop_queue;

void init_loopqueue(loop_queue *q);//初始化
bool is_empty(loop_queue *q);//判断空
bool is_full(loop_queue *q);//判断满
int get_length(loop_queue *q);//获得长度
void insert_queue(loop_queue *q,elem_type value);//入队
void delete_queue(loop_queue *q,elem_type *e);//出队
int get_headval(loop_queue *q,elem_type *head);//获得队头元素
int get_tailval(loop_queue *q,elem_type *head);//获得队尾元素
void destory(loop_queue *q);//销毁队列
void clear(loop_queue *q);//清空队列
