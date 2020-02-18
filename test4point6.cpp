#include <cstdio>       //判断是否为素数，只要测试x是否能整除比x的平方根小的数即可
#include <math.h>
bool judge(int x)
{
	if(x<=1)
	{
		return false;
	}
	int bound=(int)sqrt(x)+1;    //计算枚举上界，宁愿多枚举一个也不要少一个
	for (int i = 2; i < bound; i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}