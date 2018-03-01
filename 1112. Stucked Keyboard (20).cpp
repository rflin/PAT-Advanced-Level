/*
题目地址：https://www.patest.cn/contests/pat-a-practise/1112
思路：只要满足连续相同字符个数不是k的整数倍，那么一定是好键
*/
#include <bits/stdc++.h>
using namespace std;
bool isWell[178],isprt[178];
int k,i;
char keys[1024];
string poskeys,ans;
int main()
{
	scanf("%d%s",&k,keys);
	while(keys[i])
	{
		int j=i+1;
		while(keys[j]==keys[i]) ++j;
		if((j-i)%k) isWell[keys[i]-'\0']=1;
		i=j;
	}
	i=0;
	while(keys[i])
	{
		int w=keys[i];
		ans+=w;
		if(isWell[w]) ++i;
		else
		{
			if(!isprt[w]) poskeys+=w,isprt[w]=1;
			i+=k;
		}
	}
	cout<<poskeys<<endl<<ans<<endl;
	return 0;
}
