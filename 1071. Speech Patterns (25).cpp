#include <bits/stdc++.h>
using namespace std;
int main()
{
	stringstream ss;
	char x;
	while((x=getchar())!='\n')
	{
		if(isalnum(x)) ss<<string(1,tolower(x));
		else ss<<string(1,' ');
	}
	map<string,int> mp;
	string word;
	while(ss>>word) mp[word]++;
	int count=0;
	for(auto x:mp)
	{
		if(x.second>count)
		{
			count=x.second;
			word=x.first;
		}
	}
	cout<<word<<" "<<count<<endl;
	return 0;
}
