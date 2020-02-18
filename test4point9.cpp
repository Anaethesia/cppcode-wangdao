#include <cstdio>     //从2到n的素数
//思想：若当前整数没有因为它是某个小于其的素数的倍数而被标记成非素数则判定为素数，并标记它所有的倍数为素数，然后继续遍历下一个数
//此时没有标记的数字就是我们要求的素数，
int prime[10000]; //保存筛得的素数
int primesize;
bool mark[10001]; //标记true则为素数
void init()
{
	for (int i = 1; i <=10000; i++)
	{
		mark[i]=false;
	}
}
primesize=0;
for (int i = 2; i <=10000; i++)
{
	if(mark[i]=true)
	{
		continue;
	}
	prime[primesize++]=i;    //否则又得到一个新的素数
	for(int j=i*i;j<=10000;j+=j)//从i*i开始，i倍数的都不是素数，进行标记
	{
		mark[j]=true;
	}

}