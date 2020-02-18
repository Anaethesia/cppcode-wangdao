#include <cstdio>                     //十进制的转换
int main(int argc, char const *argv[])
{
	long long a,b;
	int m;
	while(scanf("%d",&m)!=EOF)
	{
		if(m==0)
		{
			break;
		}
		scanf("%lld%lld",&a,&b);
		a=a+b;
		int ans[50];size=0;
		do
		{
			ans[size++]=a%m;
			a=a/m;
		}while(a!=0);
		for (int i = 0; i < size; i++)
		{
			printf("%d\n",ans[i]);
		}
		printf("\n");
	}
	
	return 0;
}