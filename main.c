#include "ShortestPath.h"
main(void)
{
	MGraph G;
	CreateMGraph(&G);

	//int v0;
	//Patharc P;
	//ShortestPathTable D;
	//for (v0 = 0; v0 < 4; ++v0)
	//{
	//	ShortestPath_Dijkstra(&G, v0, &P, &D);
	//}
	//printf("\n");

	PathMat Mat;
	ShortestPath S;
	ShortestPath_Floyd(&G, &Mat, &S);


	system("pause");
	return 0;
}