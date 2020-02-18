#include <cstdio>           //构造一个二叉排序树
#include <cstring>
struct Node
{
	Node *lchild;
	Node *rchild;
	int c;
}Tree[110];                    //标准的树的格式
int loc;
Node *creat()                  //申请未使用的结点
{
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}
void postOrder(Node *T)    //后序遍历
{
	if(T->lchild!=NULL)
	{
		postOrder(T->lchild);
	}
	if(T->rchild!=NULL)
	{
		postOrder(T->rchild);
	}
	printf("%d\n",T->c);
}
void inOrder(Node *T)     //中序遍历
{
	if(T->lchild!=NULL)
	{
		inOrder(T->lchild);
	}
	printf("%d\n",T->c );
	if(T->rchild!=NULL)
	{
		inOrder(T->rchild);
	}
}
void preOrder(Node *T)
{
	printf("%d\n",T->c);
	if(T->lchild!=NULL)
	{
		preOrder(T->lchild);
	}
	if(T->rchild!=NULL)
	{
		preOrder(T->rchild);
	}
}
Node* insert(Node* T,int x)     //插入数字
{
	if(T==NULL)
	{
		T=creat();     //当前树为空，建立结点
		T->c=x;
		//return T;
	}
	else if (T->c>x)
	{
		T->lchild=insert(T->lchild,x);
	}
	else if(T->c<x)
	{
		T->rchild=insert(T->rchild,x);
	}
    return T;
}
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		loc=0;
		Node *T=NULL;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d",&x);
			T=insert(T,x);
		}
		preOrder(T);
		printf("\n");
		inOrder(T);
		printf("\n");
		postOrder(T);
		printf("\n");
	}
	return 0;
}