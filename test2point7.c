#include<stdio.h>
int main(int argc, char const *argv[])
{
	int h;
	while(scanf("%d",&h)!=EOF)
	{
		int maxline=h+(h-1)*2;
		for (int i = 1; i <= h; i++)
		{
			for (int j= 1; j<=maxline; j++)
			{
				if(j<maxline-h-(i-1)*2+1)
				{
					printf(" ");
				}
				else
				{
					printf("*" );
				}
			}
			printf("\n");
		}
	}
	
	return 0;
}