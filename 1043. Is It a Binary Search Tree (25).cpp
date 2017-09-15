#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n,note=1;
vector<int> v,ino,pos;
void build(int L,int R,bool bst)
{
	if(L>R) return;
	int root=v[L],idx=L+1;
	if(bst) while(idx<=R&&v[idx]<root)++idx;
	else while(idx<=R&&v[idx]>=root)++idx;
	build(L+1,idx-1,bst);
	ino.push_back(root);
	build(idx,R,bst);
	pos.push_back(root);
}
bool check(int n,bool bst)
{
	int i=0;
	if(bst) while(i<n-1&&ino[i]<=ino[i+1]) ++i;
	else while(i<n-1&&ino[i]>=ino[i+1]) ++i;
	if(i<n-1) return false;
	return true;
}
int main()
{
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;++i)
		cin>>v[i];
	build(0,n-1,1);
	if(check(n,1))
	{
		cout<<"YES\n";
		for(int i=0;i<n;++i)
			i==n-1?cout<<pos[i]:cout<<pos[i]<<" ";
	}
	else
	{
		ino.clear();
		pos.clear();
		build(0,n-1,0);
		if(check(n,0))
		{
			cout<<"YES\n";
			for(int i=0;i<n;++i)
				i==n-1?cout<<pos[i]:cout<<pos[i]<<" ";
		}
		else cout<<"NO";
	}
	return 0;
}
