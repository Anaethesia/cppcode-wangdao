#include <cstdio>                  //a进制数转换成b进制数    
#include <cstring>
int main(int argc, char const *argv[])
{
	int a,b;
	char str[40];
	while(scanf("%d%s%d",&a,str,b)!=EOF)
	{
		int tmp=0,length=strlen(str),c=1;
		for (int i = length-1; i >=0; i--)
		{
			int x;
			if(str[i]>='0'&&str[i]<='9')
			{
				x=str[i]-'0';
			}
			else if(str[i]>='a'&&str[i]<='z')
			{
				x=str[i]-'a'+10;

			}
			else
			{
				x=str[i]-'A'+10;
			}
			tmp+=c*x;
			c=c*a;
		}
		char ans[40];
		int size=0;
		do
		{
			int x=tmp%b;
			ans[size++]=(x<10)?x='0':x-10+'A';
			tmp=tmp/b;
		}while(tmp!=0);
		for (int i = 0; i < size; i++)
		{
			printf("%c\n",str[i] );
		}
		printf("\n");

	}
	return 0;
}