/*
题目地址：https://www.patest.cn/contests/pat-a-practise/1112
思路：一定要先判断哪些键是坏的
*/
#include <iostream>
#include <vector>
#include <cstring> 
#include <algorithm>
#include <cstdio>
using namespace std;
bool isStucked[128],check[128],iscollect[128];
int k;
char str[1024];
string possKey,ans;
void stuckedKey(char str[],int n)
{
	int cur=0,next=0;
	while(next!=n)
	{
		int idx=str[cur];
		while(next!=n&&str[cur]==str[next]) ++next;
		if((next-cur)%k) check[idx]=true;//只要有余数不为0的，那么肯定是好的
		if(!check[idx]) isStucked[idx]=true;
		else isStucked[idx]=false;
		cur=next;
	}
	for(int i=0;i<n;++i)
	{
		ans+=str[i];
		if(isStucked[str[i]-'\0'])
		{
			if(!iscollect[str[i]-'\0'])
			{
				possKey+=str[i];
				iscollect[str[i]-'\0']=true;
			}
			i+=k-1;
		}
	}
}
int main()
{
	scanf("%d\n",&k);
	gets(str);
	stuckedKey(str,strlen(str));
	cout<<possKey<<endl<<ans;
	return 0;
}
