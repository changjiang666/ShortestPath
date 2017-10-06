#include "MGraph.h"
#include <stdio.h>

void CreateMGraph(MGraph *G)
{
	int i, j, k, weight;
	printf("please input the number of vertex and eage:");
	scanf_s("%d,%d", &G->vexNum, &G->arcNum);
	getchar();

	printf("please input the vertex data:");
	for (i = 0; i < G->vexNum; ++i)
	{
		scanf_s("%c", &G->vexs[i]);
	}
	getchar();

	for (i = 0; i < G->vexNum; ++i)
	{
		for (j = 0; j < G->vexNum; ++j)
		{
			G->arc[i][j] = INF;
			if (i == j)
			{
				G->arc[i][j] = 0;
			}
		}
	}
	

	for (k = 0; k < G->arcNum; ++k)
	{
		printf("please input the eage:");
		scanf_s("%d,%d,%d", &i, &j, &weight);
		G->arc[i][j] = G->arc[j][i] = weight;
	}
}

