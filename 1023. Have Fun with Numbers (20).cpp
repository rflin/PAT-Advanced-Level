#include <bits/stdc++.h>
using namespace std;
string doubleNums(const string &nums)
{
	string results;
	int n=nums.size(),add=0;
	for(int i=0;i<n;++i)
	{
		results+='0'+((nums[n-1-i]-'0')*2+add)%10;
		add=((nums[n-1-i]-'0')*2+add)/10;
	}
	if(add>0) results+='0'+add;
	reverse(results.begin(),results.end());
	return results;
}
bool judgeNums(string &a,string &b)
{
	vector<int> counts(10,0);
	for(char x:a) counts[x-'0']++;
	for(char x:b) counts[x-'0']--;
	for(int x:counts) if(x) return false;
	return true;
}
int main()
{
	string nums,results;
	cin>>nums;
	results=doubleNums(nums);
	if(judgeNums(nums,results)) cout<<"Yes\n";
	else cout<<"No\n";
	cout<<results;
	return 0;
}
