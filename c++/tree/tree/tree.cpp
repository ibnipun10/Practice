// tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "treeOpp.h"


int _tmain(int argc, _TCHAR* argv[])
{
	tree* root = NULL;
	int values[] = { 8, 2, 4, 5, 9, 13, 4, 44 };
 
	for (int i = 0; i < 8; i++){
		root = createTree(values[i], root);
	}

	//InOrder(root);
	addLevel(root, 0);
	BFS(root);
	return 0;
}

