#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define N 10   //定义允许添加的最大顶点个数

typedef int InfoType;
//边表
typedef struct Tnode {
	int adjvex;    //边节点的值
	Tnode *next;  //next 指向下一个边节点
	InfoType *info; //边上的权值
}edge;

//顶点表
typedef struct Vertexnode {
	int data;
	edge *first;  //指向第一个边节点的指针
}Vertexnode, Alist[N];

typedef struct Graph {
	int v, e;
	Alist List;
}Graph;

Graph CreatUnDrectedNet(Graph G);
//int Print_Demo(Graph G);
//void Print_Weight(Graph G);
void Greed(Graph G);