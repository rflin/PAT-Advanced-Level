#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int m,n,k;
int main()
{
	cin>>m>>n>>k;
	while(k--)
	{
		int idx,vp=1,ret=1;
		stack<int> stk;
		for(int i=0;i<n;++i)
		{
			cin>>idx;
			if(vp<=idx)
			{
				while(vp<=idx&&(int)stk.size()<=m) stk.push(vp++);
				if((int)stk.size()>m)
				{
					ret=0;
					break;
				}
				stk.pop();
			}
			else
			{
				if(!stk.empty()&&stk.top()==idx)
				{
					stk.pop();
					continue;
				}
				ret=0;
				break;
			}
		}
		if(ret==0)
		{
			while(cin.get()!='\n');
			cout<<"NO"<<endl;
		}
		else cout<<"YES"<<endl;
	}
	return 0;
}
