#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void format(int n)
{
	int k=n,len=0;
	string str;
	while(k)
	{
		str+='0'+k%10;
		k/=10;
		++len;
		if(len%3==0&&k!=0) str+=',';
	}
	if(n==0) str+='0';
	for(auto it=str.rbegin();it!=str.rend();++it)
		cout<<*it;
}
int main()
{
	int a,b,c;
	cin>>a>>b;
	c=a+b;
	if(c<0) cout<<"-";
	format(abs(c));
	return 0;
}
