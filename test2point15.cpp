//贪婪算法计算最多能看多少节目的问题
#include <cstdio>
#include <algorithm>
using namespace std;
struct program
{
	int starttime;
	int endtime;
	bool operator < (const program &A) const
	{
		return endtime<A.endtime;
	}
}buf[100];
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		{
			break;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&buf[i].starttime,&buf[i].endtime);
		}
		sort(buf,buf+n);
		int currentime=0;
		int ans=0;
		for (int i = 0; i < n; i++)
		{
			if(currentime<buf[i].starttime)
			{
				currentime=buf[i].endtime;
				ans++;
			}
		}
		printf("%d\n",ans );
	}

	return 0;
}
