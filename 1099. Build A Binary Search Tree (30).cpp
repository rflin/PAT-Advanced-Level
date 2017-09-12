#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode
{
	int val,left,right;
	TreeNode(int v=0,int l=-1,int r=-1):val(v),left(l),right(r){}
};
vector<TreeNode> tree;
vector<int> v;
vector<vector<int>> lev;
int n,k;
void getLevTra(int r,int dep)
{
	if(dep+1>lev.size()) lev.push_back(vector<int>());
	if(r!=-1)
	{
		getLevTra(tree[r].left,dep+1);
		lev[dep].push_back(v[k++]);
		getLevTra(tree[r].right,dep+1);
	}
}
int main(int argc, char const *argv[])
{
	cin>>n;
	v.resize(n);
	for(int i=0;i<n;++i)
	{
		int l,r;
		cin>>l>>r;
		tree.push_back(TreeNode(0,l,r));
	}
	for(int i=0;i<n;++i) cin>>v[i];
	sort(v.begin(),v.end());
	getLevTra(0,0);
	for(auto xv:lev)
	{
		for(auto x:xv) --k==0?cout<<x:cout<<x<<" ";
	}
	return 0;
}
