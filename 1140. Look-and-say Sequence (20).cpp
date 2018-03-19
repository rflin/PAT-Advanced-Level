#include <bits/stdc++.h>
using namespace std;
string lasseq(string s)
{
	string res;
	int len=s.size(),i=0;
	while(i<len){
		res+=s[i];
		int j=i;
		while(j<len&&s[j]==s[i]) ++j;
		res+=to_string(j-i);
		i=j;
	}
	return res;
}
int main()
{
	int d,n;
	cin>>d>>n;
	string res(1,d+'0');
	while(--n){
		res=lasseq(res);
	}
	cout<<res<<endl;
	return 0;
}
