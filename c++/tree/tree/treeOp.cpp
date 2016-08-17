#include <stdafx.h>
#include "treeOpp.h"
#include <iostream>





tree* createTree(int data, tree* node){
	if (node == NULL){
		node = new tree();
		node->data = data;
		node->left = NULL;
		node->right = NULL;
	}
	else
	{
		if (data < node->data)
			node->left = createTree(data, node->left);
		else
			node->right = createTree(data, node->right);
	}

	return node;

}

//---- Traversals ---------
void InOrder(tree *root){
	if (root == NULL)
		return;
	else
	{
		InOrder(root->left);
		cout << root->data;
		InOrder(root->right);
	}
}

void PreOrder(tree *root){
	if (root == NULL) return;
	else
	{
		cout << root->data;
		PreOrder(root->left);		
		PreOrder(root->right);
	}
}

void addLevel(tree* root, int level){
	if (root == NULL) return;
	else
	{
		root->level = level;
		addLevel(root->left, level - 1);
		addLevel(root->right, level + 1);
	}
}



void BFS(tree *root){
	if (root == NULL) return;
	else
	{
		queue<tree*> bfsqueue;
		bfsqueue.push(root);
		map<int, int> mHead;

		while (!bfsqueue.empty()){
			tree* node = bfsqueue.front();
			bfsqueue.pop();

			if (node->left != NULL)
				bfsqueue.push(node->left);
			if (node->right != NULL)
				bfsqueue.push(node->right);

			mHead[node->level] = node->data;

		}

		PrintWallOfTree(mHead);

	}
}

//As per this 
/*https://docs.google.com/document/d/13QKfckANc8DTp2Nzb3wbd9wVs827k2vdxxHkXiVH088/edit?ts=57b2a9dd  */
void PrintWallOfTree(map<int, int> mHead)
{
	map<int, int>::iterator iter = mHead.begin();
	for (; iter != mHead.end(); iter++){
		cout << iter->second;
	}
}