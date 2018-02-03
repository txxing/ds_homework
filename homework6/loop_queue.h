
#define MaxSize 11
typedef int elem_type;
typedef struct Loop_Queue
{
	elem_type data[MaxSize];
	int front;
	int rear;
	
}loop_queue;

void init_loopqueue(loop_queue *q);//��ʼ��
bool is_empty(loop_queue *q);//�жϿ�
bool is_full(loop_queue *q);//�ж���
int get_length(loop_queue *q);//��ó���
void insert_queue(loop_queue *q,elem_type value);//���
void delete_queue(loop_queue *q,elem_type *e);//����
int get_headval(loop_queue *q,elem_type *head);//��ö�ͷԪ��
int get_tailval(loop_queue *q,elem_type *head);//��ö�βԪ��
void destory(loop_queue *q);//���ٶ���
void clear(loop_queue *q);//��ն���
