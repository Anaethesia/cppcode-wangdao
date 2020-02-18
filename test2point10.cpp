//根据学号进行二分查找问题
#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <cstring>
using namespace std;
struct Student
	{
		char no[100];
		char name[100];
		int age;
		char sex[5];
		bool operator <(const Student &A)const
		{
			return strcmp(no,A.no)<0;
		}
	}buf[1000];
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%s%s%s%d",buf[i].no,buf[i].name,buf[i].sex,buf[i].age);
		}
		sort(buf,buf+n);
		int t;
		scanf("%d",&t);
		while(t--!=0)
		{
			int ans=-1;
			char x[30];
			scanf("%s",x);
			int top=n-1,base=0;
			while(base<=top)
			{
				int mid=(base+top)/2;
				int temp=strcmp(buf[mid].no,x);
				if(temp==0)
				{
					ans=mid;
				}
				else if(temp<0)
				{
					base=mid+1;

				}
				else
				{
					top=mid-1;
				}

			}
			if(ans==-1)
			{
				printf("Wrong answer\n");
			}
			else
			{
				printf("%s%s%s%d\n",buf[ans].no,buf[ans].name,buf[ans].sex,buf[ans].age);
			}
		}
	}
	return 0;
}
