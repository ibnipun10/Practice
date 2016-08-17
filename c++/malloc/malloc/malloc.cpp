// malloc.cpp : Defines the entry point for the console application.
//

/*
This program is to create a 2D array using single malloc call
*/
#include "stdafx.h"
#include "stdlib.h"
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int row = 2, col = 3;
	int totalSpace = row * col * sizeof(int);
	int header = row * sizeof(int *);

	int tomalloc = totalSpace + header;
	int **start = (int **)malloc(tomalloc);

	int *buf = (int*)(start)+header;

	for (int i = 0; i < row; i++){
		start[i] = buf + i*col;
	}

	start[1][1] = 10;
	start[0][2] = 20;

	cout << start[0][2];
	return 0;
}

