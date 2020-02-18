#include <stdio>
#include <vector>
using namespace std;
struct Edge
{
	int nextNode;        //下一个结点或编号
	int cost;            //该边的权值
	
};
vector<Edge> edge[N];      
for (int i = 0; i < N; i++)   //遍历所有结点
{
	edge[i].clear();         //清空其单链表
}
Edge tmp;
tmp.nextNode=3;
tmp.cost=38;
edge[1].push_back(tmp);       //将该边加入结点1的单链表中
edge[1].erase(edge[1].begin()+i,edge[1].begin()+j+1); 
//i第一个要删除的元素编号，i最后一个要删除的元素编号+1