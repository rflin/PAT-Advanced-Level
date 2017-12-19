#include <bits/stdc++.h>
using namespace std;
struct record
{
	string name,id;
	int score;
	record(string namex="",string idx="",int scorex=0):name(namex),id(idx),score(scorex){}
	bool operator<(const record &a)
	{
		return score>a.score;
	}
};
vector<record> v;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		string name,id;
		int score;
		cin>>name>>id>>score;
		v.push_back(record(name,id,score));
	}
	sort(v.begin(),v.end());
	int L,R;
	cin>>L>>R;
	bool ret=false;
	for(auto &x:v)
	{
		if(x.score<=R&&x.score>=L)
		{
			cout<<x.name<<" "<<x.id<<endl;
			ret=true;
		}
	}
	if(ret==false)
		cout<<"NONE"<<endl;
	return 0;
}
