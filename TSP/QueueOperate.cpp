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

int EnQueue(LinkQueue &Q, QEelement e)  //����Ԫ��Ϊ�µĶ�βԪ��
{
	Queueptr p = (Queueptr)malloc(sizeof(QNode));
	if (!p)
		printf("�洢�ռ����ʧ��\n");
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return 1;
}

int Dequeue(LinkQueue &Q, QEelement &e)  //����ͷԪ�س���
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