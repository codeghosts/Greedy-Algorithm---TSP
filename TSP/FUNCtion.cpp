#include "Head.h"
#include "Queue.h"

Graph CreatUnDrectedNet(Graph G)
{
	int n = 0;
	int x, y, weight;
	edge *p, *q;
	printf("输入无向网的顶点数和边数\n");
	scanf_s("%d %d", &G.v, &G.e);
	for (int i = 1; i <= G.v; i++)
	{
		scanf_s("%d", &n);
		G.List[i].data = n;
		G.List[i].first = NULL;
	}
	printf("建立边集\n");
	printf("请输入边上的顶点和权值 \n");
	for (int i = 1; i <= G.e; i++)
	{
		scanf_s("%d %d %d", &x, &y, &weight);
		printf("顶点%d--顶点%d (%d)\n", x, y, weight);
		p = (edge *)malloc(sizeof(edge));
		q = (edge *)malloc(sizeof(edge));
		p->info = (InfoType *)malloc(sizeof(InfoType));
		q->info = (InfoType *)malloc(sizeof(InfoType));
		p->adjvex = y;
		q->adjvex = x;

		*(p->info) = weight;
		*(q->info) = weight;

		p->next = G.List[x].first;
		G.List[x].first = p;
		q->next = G.List[y].first;
		G.List[y].first = q;
	}
	return G;
}

void Greed(Graph G)
{
	int ver1, ver2, u, e;
	int i = 1;
	int MIN = 0;
	int temp;
	LinkQueue Q;
	int visited[N];
	edge *adj;
	for (ver1 = 1; ver1 <= G.v; ver1++)
	{
		visited[ver1] = 0;
	}
	InitQueue(Q);
	for (ver1 = 1; ver1 <= G.v; ver1++)
	{
		if (!visited[ver1])
		{
			temp = 9999;
			visited[ver1] = 1;
			if (*(G.List[ver1].first->info) < temp)
				temp = *(G.List[ver1].first->info);
			EnQueue(Q, ver1);
			while (Q.rear != Q.front && i < G.v)
			{
				Dequeue(Q, ver2);
				adj = G.List[ver2].first;
				e = adj->adjvex;
				while (adj != NULL)
				{
					u = adj->adjvex;
					if (!visited[u])
					{
						if (*(adj->info) < temp)
						{
							e = adj->adjvex;
							temp = *(adj->info);
						}
					}
					adj = adj->next;
				}
				MIN += temp;
				temp = 9999;
				visited[e] = 1;
				printf("%d ", e);
				EnQueue(Q, e);
				i++;
			}
		}
	}
	printf("1\n");
	printf("最短距离为\n");
	printf("%d\n", MIN);
}