#include "ShortestPath.h"
#include <stdio.h>

void ShortestPath_Dijkstra(MGraph *G, int V0, Patharc *P, ShortestPathTable *D)
{
	int v, w, k;
	int min;
	int final[MAXVEX];

	//变量的初始化
	for (v = 0; v < G->vexNum; ++v)
	{
		(*P)[v] = V0;
		(*D)[v] = G->arc[V0][v];
		final[v] = 0;
	}
	final[V0] = 1;
	(*D)[V0] = 0;

	//求V0到其他各个顶点的最短路径
	for (v = 1; v < G->vexNum; ++v)
	{
		min = INF;
		for (w = 0; w < G->vexNum; ++w)
		{
			if (!final[w] && min > (*D)[w])
			{
				min = (*D)[w];
				k = w;
			}
		}
		final[k] = 1;

		for (w = 0; w < G->vexNum; ++w)
		{
			if (!final[w] && (*D)[w] > min + G->arc[k][w])
			{
				(*D)[w] = min + G->arc[k][w];
				(*P)[w] = k;
			}
		}
	}

	// 打印结果
	for (v = 0; v < G->vexNum; ++v)
	{
		if (v == V0)
			continue;
			
		int k;
		printf("V%d - V%d		weight: %d", V0, v, (*D)[v]);
		printf("	path: %d", v);

		k = (*P)[v];
		while (k != V0)
		{
			printf("<- %d", k);
			k = (*P)[k];
		}
		printf("<- %d\n", V0);
	}
}

void ShortestPath_Floyd(MGraph *G, PathMat *P, ShortestPath *D)
{
	int k, w, v;

	//初始化变量   
	for (v = 0; v < G->vexNum; ++v)
		for (w = 0; w < G->vexNum; ++w)
		{
			(*D)[v][w] = G->arc[v][w];
			(*P)[v][w] = w;
		}

	//修正权值和路径
	for (k = 0; k < G->vexNum; ++k)
	{
		for (v = 0; v < G->vexNum; ++v)
		{
			for (w = 0; w < G->vexNum; ++w)
			{
				if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w])
				{
					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];
					(*P)[v][w] = (*P)[v][k];
				}
			}
		}
	}


	//打印最短路径的结果
	for (v = 0; v < G->vexNum; ++v)
	{
		for (w = v + 1; w < G->vexNum; ++w)
		{
			int k;
			printf("V%d - V%d	weight: %d", v, w, (*D)[v][w]);
			printf("	path: %d", v);

			k = (*P)[v][w];
			while (k != w)
			{
				printf("-> %d", k);
				k = (*P)[k][w];
			}
			printf("->%d\n", w);
		}
	}

}