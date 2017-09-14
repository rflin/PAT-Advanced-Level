/*
题目地址：https://www.patest.cn/contests/pat-a-practise/1116
*/
#include <iostream>
#include <vector>
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
struct node
{
	int id;
	string award;
	node(int x=-1,string aw="Are you kidding?"):id(x),award(aw){}
};
vector<node> v(10000);
int n,idx,k;
bool isChecked[10000];
bool isPrime(int n)
{
	for(int i=2;i*i<=n;++i)
		if(n%i==0) return false;
	return true;
}
int main()
{
	scanf("%d\n",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&idx);
		if(i==1) v[idx]=node(idx,"Mystery Award");
		else if(isPrime(i)) v[idx]=node(idx,"Minion");
		else v[idx]=node(idx,"Chocolate");
	}
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d",&idx);
		if(!isChecked[idx])
		{
			printf("%04d: %s\n",idx,v[idx].award.c_str());
			if(v[idx].id!=-1)isChecked[idx]=true;
		}
		else printf("%04d: Checked\n",idx);
	}
    return 0;
}
