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
/*     1
     /  \
    2    3
    /\   /\
   4  5  6  7

for this tree print 4,2,6,3,7
As seen from the top of the tree
*/
void PrintWallOfTree(map<int, int> mHead)
{
	map<int, int>::iterator iter = mHead.begin();
	for (; iter != mHead.end(); iter++){
		cout << iter->second;
	}
}


/*
Convert the tree into a Doubly linked list inplace
*/
tree* ConvertTodll(tree* node){

	static tree* temp = NULL, *head = NULL;
	if (node == NULL){ return NULL; }
	else
	{
		ConvertTodll(node->left);
		if (head == NULL) head = node;
		if (temp != NULL)
			temp->right = node;
		
		
		node->left = temp;
		temp = node;

		ConvertTodll(node->right);

	}

	return head;
}

void AltPrint(tree *root, int level, int horlevel, bool bOdd){
	if (root != NULL){
		if (level == 0)
		{
			cout << root->data;
			AltPrint(root->left, level - 1, horlevel + 1, bOdd);
			AltPrint(root->right, level + 1, horlevel + 1, bOdd);
		}
		else if (level < 0){
			if (horlevel % 2 != 0)
				cout << root->data;
			AltPrint(root->left, level - 1, horlevel + 1, bOdd);
		}
		else if (level >0 ){
			if(horlevel % 2 == 0)
				cout << root->data;
			AltPrint(root->right, level + 1, horlevel + 1, bOdd);
		}
	}
}