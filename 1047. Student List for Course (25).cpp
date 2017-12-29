#include <bits/stdc++.h>
using namespace std;
struct node
{
	char name[8];
};
vector<vector<node>> v;
bool cmp(const node &a,const node &b)
{
	return strcmp(a.name,b.name)<0;
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	v.resize(k+1);
	for(int i=0;i<n;++i)
	{
		node student;
		int cnt,courseNum;
		scanf("%s %d",student.name,&cnt);//读入学生name和课程总数
		while(cnt--)
		{
			scanf("%d",&courseNum);//课程号
			v[courseNum].push_back(student);//对应课程号存入学生信息
		}
	}
	for(int i=1;i<=k;++i)
	{
		cout<<i<<" "<<v[i].size()<<endl;
		sort(v[i].begin(),v[i].end(),cmp);//对每个课程号对应的学生名字排序
		for(auto student:v[i])
			printf("%s\n",student.name);
	}
	return 0;
}
