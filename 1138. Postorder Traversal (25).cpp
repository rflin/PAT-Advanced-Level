#include <bits/stdc++.h>
using namespace std;
int pre[50002],ino[50002],ans;
void solve(int preL,int preR,int inoL,int inoR)
{
	if(preL>preR)return;
	int idx=inoL,pdx=preL;
	int root=pre[preL];
	while(root!=ino[idx])++idx,++pdx;
	ans=root;
	if(preL+1<=pdx)
		solve(preL+1,pdx,inoL,idx-1);
	else
		solve(pdx+1,preR,idx+1,inoR);
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
		scanf("%d",&pre[i]);
	for(int i=0;i<n;++i)
		scanf("%d",&ino[i]);
	solve(0,n-1,0,n-1);
	cout<<ans;
	return 0;
}
