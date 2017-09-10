#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n,s;
vector<int> ino,pre;
stack<int> stk;
void build(int preL,int preR,int inoL,int inoR)
{
	if(preL>preR) return;
	int e=pre[preL],idx=inoL,pdx=preL;
	while(idx<=inoR&&e!=ino[idx]) idx++,pdx++;
	build(preL+1,pdx,inoL,idx-1);
	build(pdx+1,preR,idx+1,inoR);
	++s!=n?cout<<e<<" ":cout<<e;
}
int main()
{
	cin>>n;
	for(int i=0;i<2*n;++i)
	{
		string str;
		int x;
		cin>>str;
		if(str=="Push")
		{
			cin>>x;
			pre.push_back(x);
			stk.push(x);
		}
		else
		{
			ino.push_back(stk.top());
			stk.pop();
		}
	}
	build(0,n-1,0,n-1);
	return 0;
}
