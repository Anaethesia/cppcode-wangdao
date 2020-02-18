#include<cstdio>
int gcd(int a,int b)       //最大公约数(a>b)
{
	if(b==0)
	{
		return a;
	}
	else
	{
		return gcd(b,a%b);
	}

}
int gbs(int a, int b)          //最小公倍数
{
	return a*b/gcd(a,b);
}