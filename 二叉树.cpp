#include <iostream>
#include <cstdio>
using namespace std;
#define max 100

typedef struct node
{
	int parent;
	int lchild;
	int rchild;
	int sibling;
	int children_num;
	int depth;
	int height;
	string type;
}BTnode;

BTnode T[max];

int getDegree(int u) 
{
	int deg = 0;
	if (T[u].lchild != -1)
		deg++;
	if (T[u].rchild != -1)
		deg++;
	return deg;
}

void getdeep(int o, int deep)
{
	T[o].depth = deep;
	if (T[o].rchild != -1)
		getdeep(T[o].rchild, deep + 1);
	if (T[o].lchild != -1)
		getdeep(T[o].lchild, deep + 1);
}

int getheight(int o)
{
	int h1 = 0, h2 = 0;
	if (T[o].lchild != -1)
		h1 = getheight(T[o].lchild) + 1;
	if (T[o].rchild != -1)
		h2 = getheight(T[o].rchild) + 1;
	return T[o].height = h1> h2?h1:h2;
}

int main()
{
	int n,i,j,l,r,c,d,id;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		T[i].lchild = T[i].parent = T[i].rchild = T[i].sibling =-1;
	}
	for (i = 0; i < n; i++)
	{
		cin >> id >> l >> r;
		T[id].lchild = l;
		T[id].rchild = r;
		T[l].parent = id;
		T[r].parent = id;
		if (l != -1) T[l].sibling = r;
		if (r != -1) T[r].sibling = l;
	}
	for (i = 0; i < n; i++)
	{
		if (T[i].parent == -1)
		{
			T[i].type = "root";
		}
		else if (T[i].lchild == -1 && T[i].rchild == -1)
		{
			T[i].type = "leaf";
		}
		else
		{
			T[i].type = "internal node";
		}
	}
	int root;
	for (int i = 0; i < n; i++)
		if (T[i].parent == -1)
		{
			root = i;
			break;
		}
	getdeep(root, 0);
	getheight(root);
	for (i = 0; i < n; i++)
	{
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", i, T[i].parent, T[i].sibling, getDegree(i), T[i].depth, T[i].height);
		cout << T[i].type << endl;
	}
	return 0;
}