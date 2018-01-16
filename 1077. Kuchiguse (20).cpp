/*
题目地址：https://www.patest.cn/contests/pat-a-practise/1077
考察：字符串处理
*/
#include <bits/stdc++.h>
using namespace std;
string Kuchiguse(const string &line,const string &x)
{
	int i=line.size()-1,j=x.size()-1;
	string ret;
	while(i>=0&&j>=0)
	{
		if(line[i]==x[j]) ret=line[i]+ret;
		else break;
		--i,--j;
	}
	return ret;
}
int main()
{
	int n;
	string ret;
	cin>>n;
	cin.get();
	getline(cin,ret);
	while(--n)
	{
		string line;
		getline(cin,line);
		ret=Kuchiguse(line,ret);
	}
	if(ret.empty()) cout<<"nai";
	else cout<<ret;
	return 0;
}
