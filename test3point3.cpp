#include <queue>                         //用小顶堆（队列）做一个哈夫曼树
#include <cstdio>
using namespace std;
priority_queue<int,vector<int>,greater<int>> Q;   //定义一个小顶堆，顶是最小的元素
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		while(Q.empty()==false)       //初始化清空优先队列元素
		{
			Q.pop();
		}
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d",&x);
			Q.push(x);
		}
		int ans=0;
		while(Q.size()>1)
		{
			int a=Q.top();
			printf("a=%d\n",a );
			Q.pop();
			int b=Q.top();
			printf("b=%d\n",b );
			Q.pop();
			ans+=a+b;
			Q.push(a+b);

		}
		printf("%d\n",ans );
	}
	return 0;
}