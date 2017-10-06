#include "ShortestPath.h"
#include <stdio.h>

void ShortestPath_Dijkstra(MGraph *G, int V0, Patharc *P, ShortestPathTable *D)
{
	int v, w, k;
	int min;
	int final[MAXVEX];

	//�����ĳ�ʼ��
	for (v = 0; v < G->vexNum; ++v)
	{
		(*P)[v] = V0;
		(*D)[v] = G->arc[V0][v];
		final[v] = 0;
	}
	final[V0] = 1;
	(*D)[V0] = 0;

	//��V0������������������·��
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

	// ��ӡ���
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

	//��ʼ������   
	for (v = 0; v < G->vexNum; ++v)
		for (w = 0; w < G->vexNum; ++w)
		{
			(*D)[v][w] = G->arc[v][w];
			(*P)[v][w] = w;
		}

	//����Ȩֵ��·��
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


	//��ӡ���·���Ľ��
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