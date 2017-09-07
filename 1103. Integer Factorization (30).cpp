#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int maxsum=-1;
vector<int> ans;
void solve(vector<int> &ans,vector<int> &rp,int sum,int cur,int n,int k,int p)
{
	if(n<0||k<0) return;
	if(k==0&&n==0&&(sum>maxsum||(sum==maxsum&&ans<rp)))
	{
		ans=rp;
		maxsum=sum;
		return;
	}
	for(int i=cur;i>=1;--i)
	{
		rp.push_back(i);
		solve(ans,rp,sum+i,i,n-pow(i*1.0,p*1.0),k-1,p);
		rp.pop_back();
	}
}
int main()
{
	int n,k,p;
	cin>>n>>k>>p;
	vector<int> rp;
	solve(ans,rp,0,n,n,k,p);
	if(ans.size())
	{
		printf("%d = ",n);
		for(auto it=ans.begin();it!=ans.end();++it)
		{
			printf("%d^%d",*it,p);
			if(it!=ans.end()-1) printf(" + ");
		}
	}
	else
		printf("Impossible");
	return 0;
}
