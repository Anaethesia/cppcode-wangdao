//最短路径长度问题(两个点之间的最短路径）--FLOYD算法
//邻接矩阵
//三维数组简化为二维数组
#include <cstdio>
using namespace std;
int ans[101][101];      //图的邻接矩阵
int main(int argc, char const *argv[])
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
		{
			break;
		}
		for (int i = 1; i <= n; i++)
		{
			for(int j=1;j<=n;j++)
			{
				ans[i][j]=-1;     //-1表示无穷

			}
			ans[i][i]=0;

		}
		while(m--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			ans[a][b]=ans[b][a]=c;

		}
		//开始了FLOYD算法
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for (int j = 0; j <=n; j++)
				{
					if(ans[i][k]==-1||ans[k][j]==-1)
					{
						continue;
					}
					if(ans[i][j]==-1||ans[i][j]>ans[i][k]+ans[k][j])
					{
						ans[i][j]=ans[i][k]+ans[k][j];
					}

				}
			}
		}
		printf("%d\n",ans[1][n] );
	}
	return 0;
}