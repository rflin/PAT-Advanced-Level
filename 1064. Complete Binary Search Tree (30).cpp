#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v,tree;
int k=0,n;
void build(int i)
{
	if(i<=n)
	{
		build(2*i);
		tree[i]=v[k++];
		build(2*i+1);
	}
}
int main(int argc, char const *argv[])
{
	cin>>n;
	v.resize(n);
	tree.resize(n+1);
	for(int i=0;i<n;++i) cin>>v[i];
	sort(v.begin(),v.end());
	build(1);
	for(unsigned int i=1;i<tree.size();++i)
		i==tree.size()-1?cout<<tree[i]:cout<<tree[i]<<" ";
	return 0;
}
