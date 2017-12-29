#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	char ch;
	bool kick[256]={};
	getline(cin,str);
	while((ch=cin.get())!='\n')
		kick[ch-'\0']=true;
	for(auto x:str)
	{
		if(!kick[x-'\0'])
			cout<<x;
	}
	return 0;
}
