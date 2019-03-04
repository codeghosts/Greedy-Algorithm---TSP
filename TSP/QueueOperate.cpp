#include "Queue.h"

int InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (Queueptr)malloc(sizeof(QNode));
	if (!Q.front)
		return 0;
	Q.front->next = NULL;
	return 1;
}

int DestroyQueue(LinkQueue &Q)
{
	while (Q.front) {
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return 1;
}

int EnQueue(LinkQueue &Q, QEelement e)  //插入元素为新的队尾元素
{
	Queueptr p = (Queueptr)malloc(sizeof(QNode));
	if (!p)
		printf("存储空间分配失败\n");
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return 1;
}

int Dequeue(LinkQueue &Q, QEelement &e)  //将队头元素出队
{
	if (Q.front == Q.rear)
		return 0;
	Queueptr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return 1;
}