#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> sets(10240);
int n,q,birdscnt,treecnt;
int find(int x)
{
	return sets[x]==x?x:sets[x]=find(sets[x]);
}
int main()
{
	cin>>n;
	for(int i=0;i<=10000;++i) sets[i]=i;
	for(int i=0;i<n;++i)
	{
		int m,h,x;
		cin>>m>>h;
		birdscnt=max(birdscnt,h);
		for(int i=0;i<m-1;++i)
		{
			cin>>x;
			birdscnt=max(birdscnt,x);
			int l1=find(h),l2=find(x);
			if(l1!=l2) sets[l2]=l1;
		}
	}
	for(int i=1;i<=birdscnt;++i)
	{
		if(sets[i]==i)++treecnt;
	}
	cout<<treecnt<<" "<<birdscnt<<endl;
	cin>>q;
	while(q--)
	{
		int b1,b2;
		cin>>b1>>b2;
		find(b1)==find(b2)?cout<<"Yes\n":cout<<"No\n";
	}
	return 0;
}
