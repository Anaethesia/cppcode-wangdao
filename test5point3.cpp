//Kruskal 算法       MST最小生成树
#include <stdio>
#include <algorithm>
using namespace std;
#define N 101
int Tree[N];
int findRoot(int x)
{
	if(Tree[x]==-1)
	{
		return x;
	}
	else
	{
		int tmp=findroot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}
struct Edge
{
	int a,b;      //顶点编号
	int cost;     //该边权值
	bool operator < (const Edge &A) const  //重载小于号使其可以按照边权从小到大排列
	{
		return cost<A.cost;

	}
}edge[6000];
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		for (int i = 0; i < n*(n-1)/2; i++)
		{
			scanf("%d%d%d",&edge[i].a,&edge[i].b,edge[i].cost);
			
		}
		sort(edge+1,edge+1+n*(n-1)/2);/* 按照边权值递增排列所有的边 */
		for(int i=1;i<=n;i++)
		{
			Tree[i]=-1;
		}
		int ans=0;
		for (int i = 0; i < n*(n-1)/2; i++)
		{
			int a=findRoot(edge[i].a);
			int b=findRoot(edge[i].b);          //查找该边两个顶点的集合信息
			if(a!=b)
			{
				Tree[a]=b;/* 合并两个集合*/
				ans+=edge[i].cost;
		}
		printf("%d\n",ans );
	}
	return 0;
}