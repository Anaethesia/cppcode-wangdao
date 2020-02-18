#include <cstdio>       //二分求幂
int main(int argc, char const *argv[])
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(a==0&&b==0)
		{
			break;
		}
		int ans=1;
		while(b!=0)
		{
			if(b%2==1)
			{
				ans*=a;
				ans%=1000 //求后三位数
			}
			b/=2;
			a*=a;  //相当于2^32=4^16，减少乘法次数
			a%=1000;
		}
		printf("%d\n",ans );
	}
	
	return 0;
}