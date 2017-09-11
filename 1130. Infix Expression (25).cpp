#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
struct TreeNode
{
	string val;
	int left,right;
	TreeNode(string str="",int L=-1,int R=-1):val(str),left(L),right(R){}
};
vector<TreeNode> v;
bool root[32];
int n,r=1;
string infixExp(int x)
{
	if(x==-1) return "";
	else if(v[x].right==-1) return v[x].val;//叶节点 
	return x==r?infixExp(v[x].left)+v[x].val+infixExp(v[x].right):'('+infixExp(v[x].left)+v[x].val+infixExp(v[x].right)+')';
}
int main()
{
	cin>>n;
	v.resize(n+1);
	for(int i=1;i<=n;++i)
	{
		cin>>v[i].val>>v[i].left>>v[i].right;
		if(v[i].left!=-1) root[v[i].left]=1;
		if(v[i].right!=-1) root[v[i].right]=1;
	}
	while(root[r])++r;
	cout<<infixExp(r);
	return 0;
}
