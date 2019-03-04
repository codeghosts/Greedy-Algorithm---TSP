#include "Head.h"

int main()
{
	Graph G = { 0,0 };
	G = CreatUnDrectedNet(G);
	Greed(G);
	return 0;
}