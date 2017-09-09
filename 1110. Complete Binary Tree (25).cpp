#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define NULLint 24
using namespace std;
struct TreeNode
{
	int left,right;
	TreeNode(int L=NULLint,int R=NULLint):left(L),right(R){}
};
bool root[32];
int n;
vector<TreeNode> tree;
bool iscbt(int r,int &ret)
{
	int s;
	queue<int> q;
	q.push(r);
	while((s=q.front())!=NULLint)
	{
		ret=s;
		q.pop();
		q.push(tree[s].left);
		q.push(tree[s].right);
	}
	while(!q.empty())
	{
		s=q.front();
		q.pop();
		if(s!=NULLint)
		{
			ret=r;return false;
		}
	}
	return true;
} 
int trans(string &str)
{
	if(str[0]=='-')return NULLint; 
	int ret=0;
	for(auto it=str.begin();it!=str.end();++it) ret=ret*10+(*it-'0');
	return ret; 
}
int main()
{
	cin>>n;
	tree.resize(n*10);
	for(int i=0;i<n;++i)
	{
		string str1,str2;
		cin>>str1>>str2;
		root[tree[i].left=trans(str1)]=1;
		root[tree[i].right=trans(str2)]=1;
	}
	int r=0,ret=-1;
	while(root[r])++r;
	iscbt(r,ret)?cout<<"YES "<<ret:cout<<"NO "<<ret;
	return 0;
}
