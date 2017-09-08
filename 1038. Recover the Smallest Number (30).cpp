#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	vector<string> v;
	cin>>n;
	while(n--)
	{
		string str;
		cin>>str;
		v.push_back(str);
	}
	sort(v.begin(),v.end(),[](string &a,string &b){return a+b<b+a;});
	string ans;
	for(auto x:v)
		ans+=x;
	unsigned int k=0;
	while(ans[k]=='0')++k;
	k==ans.size()?cout<<"0":cout<<ans.substr(k,ans.size()-k);
	return 0;
}
