#include<stdio.h>
#include"sqlist.h"


void main()
{
    sqlist list;
	int q;
	init_sqlist(&list);//��ʼ������
	for(int i=0;i<10;i++)
	{
		 insert(&list,i,i*10);
	}
	insert(&list,5,45);//����Ԫ�ز���
	//show(&list);//��ӡ˳���Ԫ�ز���
	printf("%d\n",search(&list,50));//����Ԫ�ز���
	delete_pos(&list,3);//ɾ��ָ��λ��Ԫ�ز���
	//show(&list);
	delete_value(&list,70);//ɾ��Ԫ��
	//show(&list);
	printf("%d\n",get_length(&list));//���˳����Ȳ���
	get_elem(&list,5,&q);//���Ԫ�ز���
	printf("%d\n",q);
	is_empty(&list);//�ж��Ƿ�Ϊ��
	clear_sqlist(&list);//����˳���
	destroy_sqlist(&list);//����˳���

/*
	//ɾ��A�г�����B�е�Ԫ��
	sqlist listA,listB;
	init_sqlist(&listA);
	init_sqlist(&listB);
	for(int i=0;i<10;i++)
	{
		insert(&listA,i,2*(i+1));
		insert(&listB,i,3*(i+1));
	}
	for(int i=0;i<listB.len;i++)
	{
		if(search(&listA,listB.elem[i])!=-1)
		{
			delete_value(&listA,listB.elem[i]);//ɾ��A�г�����B�е�Ԫ��
		}
	}
	show(&listA);
	show(&listB);


	//˳���C��Ԫ�طǵݼ�����
   sqlist listA,listB,listC;
   init_sqlist(&listA);
   init_sqlist(&listB);
   init_sqlist(&listC);
   for(int i=0;i<10;i++)
   {
	   insert(&listA,i,2*(i+1));
	   insert(&listB,i,3*(i+1));
   }
   for(int i=0;i<listA.len;i++)
   {
	   insert(&listC,i,listA.elem[i]);
   }
   for(int i=listA.len;i<listA.len+listB.len;i++)
   {
	   insert(&listC,i,listB.elem[i-listA.len]);
   }
   show(&listC);
   for(int i=0;i<listC.len;i++)
   {
	   for(int j=i+1;j<listC.len;j++)
	   {
		   if(listC.elem[i]>listC.elem[j])
		   {
			   int temp;
			   temp=listC.elem[i];
			   listC.elem[i]=listC.elem[j];
			   listC.elem[j]=temp;
		   }
	   }
   }
 show(&listC);*/
	

}