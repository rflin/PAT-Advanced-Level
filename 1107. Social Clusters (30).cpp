#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
int person[1000+1],hobby[1000+1],n;
int main()
{
	function<int(int,int[])> finds=[&finds](int x,int parents[]){return parents[x]==x?x:parents[x]=finds(parents[x],parents);};
	cin>>n;
	for(int i=1;i<=1000;++i)
		hobby[i]=i;
	for(int i=1;i<=n;++i)
	{
		int m,head,cur;
		scanf("%d: %d",&m,&head);
		person[i]=head;
		for(int k=0;k<m-1;++k)
		{
			scanf("%d",&cur);
			int hp=finds(head,hobby);
			int cp=finds(cur,hobby);
			if(hp!=cp) hobby[cp]=hp;
		}
	}
	int ans[1000+1]={0};
	for(int i=1;i<=n;++i)
		ans[finds(person[i],hobby)]++;
	vector<int> v;
	for(int i=1;i<=1000;++i)
		if(ans[i]) v.push_back(ans[i]);
	sort(v.begin(),v.end(),greater<int>());
	cout<<v.size()<<endl;
	for(auto it=v.begin();it!=v.end();++it)
	{
		cout<<*it;
		if(it!=v.end()-1)cout<<" ";
	}
	return 0;
}
