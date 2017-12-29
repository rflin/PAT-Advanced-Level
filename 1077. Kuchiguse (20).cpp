#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<string> v;
	int n;
	cin>>n;
	cin.get();
	while(n--)
	{
		string line;
		getline(cin,line);
		v.push_back(line);
	}
	string ret;
	while(true)
	{
		if(v[0].size()==0)break;
		char last=v[0].back();
		v[0].pop_back();
		size_t i=1;
		while(i<v.size())
		{
			if(v[i].size()>0&&v[i].back()==last) v[i].pop_back();
			else break;
			++i;
		}
		if(i!=v.size())break;
		ret+=last;
	}
	while(ret.size()>0&&ret.back()==' ')ret.pop_back();
	if(ret.size()==0)
	{
		cout<<"nai";
		return 0;
	}
	for(int i=ret.size()-1;i>=0;--i)
		cout<<ret[i];
	return 0;
}
