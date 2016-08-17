#include <iostream>
#include <queue>
#include <map>

using namespace std;

class tree{
public:

	int data;
	tree *left;
	tree *right;
	int level;
};

tree* createTree(int , tree*);
void InOrder(tree *);
void BFS(tree *);
void PrintWallOfTree(map<int, int>);
void addLevel(tree*, int);