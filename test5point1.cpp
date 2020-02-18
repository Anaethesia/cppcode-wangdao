//工程畅通问题。抽象为一个图上查找连通分量的个数。
//只需求得连通分量的个数（彼此连通的结点集合），就能得到答案
//用并查集的方法，读入边后将顶点所在集合合并，表示连通。
//对所有边重复操作，最后计算所有节点被保存在几个集合，即存在多少棵树就得知有多少个连通分量（集合数减1就是还需建立多少条路将这些连通）
#include <stdio>
using namespace std;
#define N 1000
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