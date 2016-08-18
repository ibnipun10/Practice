// tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "treeOpp.h"

/*
Here is the sample tree
	      8
		 / \
		2	9
		\		\
		  4		13
		   \		\
			5		44
		   /
		  4
*/

int _tmain(int argc, _TCHAR* argv[])
{
	tree* root = NULL;
	int values[] = { 8, 2, 4, 5, 9, 13, 4, 44 };
 
	for (int i = 0; i < 8; i++){
		root = createTree(values[i], root);
	}

	//InOrder(root);
	addLevel(root, 0);

	tree* head = ConvertTodll(root);
	return 0;
}

