//拓扑排序问题--图上是否存在一个环，判断该图是否为有向无环图。
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector <int> edge[501];//邻接链表，边不存在权值，保存与其邻接的结点即可，故为int
queue <int> Q;//保存入度为0的队列
int main(int argc, char const *argv[])
{
	int inDegree[501]; //统计每个结点的入度
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
		{
			break;
		}
		for(int i=0;i<n;i++)
		{
			inDegree[i]=0;
			edge[i].clear();
		}
		while(m--)
		{
			int a,b;
			scanf("%d%d",&a,&b);      //一条由a指向b的边
			inDegree[b]++;
			edge[a].push_back(b);     //b入度加1，b加入a的邻接链表
		}
		while(Q.empty()==false)
		{
			Q.pop();
		}
		for (int i = 0; i < n; i++)
		{
			if(inDegree[i]==0)
			{
				Q.push(i);
			}
		}
		int cnt=0; //计数器
		while(Q.empty()==false)
		{
			int nowP=Q.front();
			Q.pop();
			cnt++;
			for(int i=0;i<edge[nowP].size();i++)
			{
				inDegree[edge[nowP][i]]--;
				if(inDegree[edge[nowP][i]]==0)
				{
					Q.push(edge[nowP][i]);
				}
			}
			if(cnt==n)
			{
				puts("yes");
			}
			else
			{
				puts("no");
			}
		}
	}
	return 0;
}