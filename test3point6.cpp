#include<cstdio>//判断两个序列能否构成同一个二叉搜索树
#include<cstring>
using namespace std;
struct Node
{
	Node* lchild;
	Node* rchild;
	int c;
}Tree[110];
int loc;
Node *creat()
{
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}
char str1[25],str2[25];//保存二叉排序树的遍历结果，将每一棵树的前序和中序字符串连接，得到结果字符串
int size1,size2;     //保存在字符数组中的遍历得到字符个数
char *str;             //当前正在保存字符串
int *size;            //当前正在保存字符串字符个数
void postOrder(Node *T)
{
	if(T->lchild!=NULL)
	{
		postOrder(T->lchild);
	}
	if(T->rchild!=NULL)
	{
		postOrder(T->rchild);
	}
	str[(*size)++]=T->c+'0';//将节点中的字符都放到正在保存的字符串中

}
void inOrder(Node *T)
{
	if(T->lchild!=NULL)
	{
		inOrder(T->lchild);
	}
	str[(*size)++]=T->c+'0';
	if(T->rchild!=NULL)
	{
		inOrder(T->rchild);
	}
}
Node* insert(Node *T,int x)//将数字插入二叉树中
{
	if(T=NULL)
	{
		T=creat();
		T->c=x;
	}
	else if(T->c>x)
	{
		T->lchild=insert(T->lchild,x);
	}
	else if(x>T->c)
	{
		T->rchild=insert(T->rchild,x);
	}
	return T;
}
int main(int argc, char const *argv[])
{
	int n;
	char temp[12];
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		loc=0;
		Node *T=NULL;
		scanf("%s",temp);
		for (int i = 0; temp[i]!=0 ; i++)
		{
			T=insert(T,temp[i]-'0');//按顺序将数字插入二叉树
		}
		size1=0;
		str=str1;
		size=&size1;
		postOrder(T);
		inOrder(T);
		str1[size1]=0;
		while(n--!=0)
		{
			scanf("%s",temp);
			Node *T2=NULL;
			for (int i = 0; temp[i]!=0; i++)
			{
				T2=insert(T2,temp[i]-'0');
			}
			size2=0;
			str=str2;
			size=&size2;
			postOrder(T2);
			inOrder(T2);
			str2[size2]=0;
			puts(strcmp(str1,str2)==0?"YES":"NO");

		}
	}
	return 0;
}