#include <cstdio>
int main(int argc, char const *argv[])
{
	int n;
	int buf[200];
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&buf[i]);
		}
		int ans=-1;
		int temp;
		scanf("%d",&temp);
		for (int i = 0; i < n; i++)
		{
			if(buf[i]==temp)
			{
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}