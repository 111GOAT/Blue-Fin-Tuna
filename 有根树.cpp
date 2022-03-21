#include<iostream>
#include<cstdio>

using namespace std;
#define max 100000

typedef struct node
{
	int data;
	int parent;
	int lchild;
	int rsibling;
	int depth;
	string type;
}TNode;

TNode T[max];

int getdepth(int i) //求深度法一：向上遍历到没有父节点为止，遍历的长度就是深度
{
	int depth = 0;
	while (T[i].parent != -1)
	{
		depth++;
		i = T[i].parent;
	}
	return depth;
}

int Depth[max] = { 0 };    //求深度法二：建立对应于每个节点的深度数组。
void getdepth2(int u, int depth) 
{
	Depth[u] = depth;
	if (T[u].rsibling != -1)  // 右兄弟设置为相同深度
		getdepth2(T[u].rsibling, depth);
	if (T[u].lchild != -1)  // 左孩子结点的深度设置为自己的深度 + 1
		getdepth2(T[u].lchild, depth + 1);
}


int main()
{
	int n,id,k,c,d,i,j;
	cin >> n;
	for (i = 0;i < n; i++)
	{
		T[i].depth = T[i].lchild = T[i].rsibling = T[i].parent = -1;
	}
	for (i = 0; i < n; i++)
	{
		cin >> id >> k ;
		for (j = 0; j < k; j++)
		{
			if (j == 0)
			{
				cin >> c;
				T[id].lchild = c;
				T[c].parent = id;
			}
			else
			{
				cin >> d;
				T[c].rsibling = d;
				T[d].parent = id;
				c = d;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (T[i].parent == -1)
		{
			T[i].type = "root";
		}
		else if (T[i].lchild == -1)
		{
			T[i].type = "leaf";
		}
		else
		{
			T[i].type = "internal node";
		}
	}
	for (i = 0; i < n; i++)  //法一求深度
	{
		T[i].depth = getdepth(i);
	}

	int root;                //法二求深度
	for (int i = 0; i < n; i++)    
	{
		if (T[i].parent == -1)
		{
			root = i;
			break;
		}
	}
	getdepth2(root, 0);


	for (i = 0; i < n; i++)
	{
		printf("node %d: parent = %d, depth = %d, ", i, T[i].parent, T[i].depth);
		cout << T[i].type<<", ";
		cout << "[";
		int j = 0;   //j只是用来控制输出", "的。
		for (c = T[i].lchild; c != -1; c = T[c].rsibling)
		{
			if (j != 0) cout << ", ";
			cout << c ;
			j++;
		}
		cout << "]" << endl;
	}
	return 0;
}