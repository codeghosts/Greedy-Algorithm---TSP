#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define N 10   //����������ӵ���󶥵����

typedef int InfoType;
//�߱�
typedef struct Tnode {
	int adjvex;    //�߽ڵ��ֵ
	Tnode *next;  //next ָ����һ���߽ڵ�
	InfoType *info; //���ϵ�Ȩֵ
}edge;

//�����
typedef struct Vertexnode {
	int data;
	edge *first;  //ָ���һ���߽ڵ��ָ��
}Vertexnode, Alist[N];

typedef struct Graph {
	int v, e;
	Alist List;
}Graph;

Graph CreatUnDrectedNet(Graph G);
//int Print_Demo(Graph G);
//void Print_Weight(Graph G);
void Greed(Graph G);