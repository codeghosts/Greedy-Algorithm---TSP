#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

typedef int QEelement;

typedef struct QNode {
	QEelement data;
	struct QNode *next;
}QNode, *Queueptr;

typedef struct {
	Queueptr front;  //队头指针
	Queueptr rear;   //队尾指针
}LinkQueue;

int InitQueue(LinkQueue &Q);
int DestroyQueue(LinkQueue &Q);
int EnQueue(LinkQueue &Q, QEelement e);
int Dequeue(LinkQueue &Q, QEelement &e);