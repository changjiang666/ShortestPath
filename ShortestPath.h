#pragma once
#include "MGraph.h"
#define MAXVEX		4
#define INF		65535

typedef int	Patharc[MAXVEX];
typedef int ShortestPathTable[MAXVEX];

typedef int PathMat[MAXVEX][MAXVEX];
typedef int ShortestPath[MAXVEX][MAXVEX];

//从V0到各个顶点的最短路径
void ShortestPath_Dijkstra(MGraph *G, int V0, Patharc *P, ShortestPathTable *D);

//各个顶点到其他所有顶点的最短路径
void ShortestPath_Floyd(MGraph *G, PathMat *P, ShortestPath *D);

