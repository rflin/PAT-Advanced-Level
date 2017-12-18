#include <bits/stdc++.h>
using namespace std;
void toCapital(string &str)
{
	for(auto &x:str)
		if(islower(x))x=toupper(x);
}
int main()
{
	string a,b;
	vector<bool> isOutput(128,0);
	cin>>a>>b;
	toCapital(a);
	toCapital(b);
	size_t i=0,j=0;
	while(i<a.size()&&j<b.size())
	{
		if(a[i]!=b[j])
		{
			if(isOutput[a[i]-'\0']==false)
			{
				isOutput[a[i]-'\0']=true;
				cout<<a[i];
			}
			++i;
		}
		else ++i,++j;
	}
	while(i<a.size())
	{
		if(!isOutput[a[i]-'\0'])cout<<a[i];
		++i;
	}
	return 0;
}
