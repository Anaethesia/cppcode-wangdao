//括号匹配问题
#include <cstdio>
#include <stack>
using namespace std;
stack<int> s;
char temp[110];
char ans[110];
int main(int argc, char const *argv[])
{
	while(scanf("%s",temp)!=EOF)
	{
		int i;
		for (i = 0; temp[i]!=0; i++)
		{
			if(temp[i]=='(')
			{
				s.push(i);
				ans[i]=' ';
			}
			else if(temp[i]==')')
			{
				if(s.empty()==false)
				{
					s.pop();
					ans[i]=' ';
				}
				else
				{
					ans[i]='?';
				}
			}
			else
			{
				ans[i]=' ';
			}
		}
		while(s.empty()==false)
		{
			ans[s.top()]='$';
			s.pop();
		}
		ans[i]=0;//为了输出形成字符串，在其最后一个字符添加一个空字符
		puts(temp);
		puts(ans);
	}
	return 0;
}