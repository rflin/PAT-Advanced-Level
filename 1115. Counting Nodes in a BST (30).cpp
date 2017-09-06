#include <iostream>
#include <cstdio>
#include <functional>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left,*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
void insert(int val,TreeNode *&r)
{
	if(r==NULL)
	{
		TreeNode *p=new TreeNode(val);
		r=p;
		return;
	}
	else if(r->val<val)
		insert(val,r->right);
	else
		insert(val,r->left);
}
void solve(TreeNode *r,int lev,const int lowest,int &n1,int &n2)
{
	if(r==NULL) return;
	if(lev==lowest) n1++;
	if(lev==lowest-1) n2++;
	solve(r->left,lev+1,lowest,n1,n2);
	solve(r->right,lev+1,lowest,n1,n2);
}
int main(int argc, char const *argv[])
{
	int n,val;
	TreeNode *r=NULL;
	cin>>n;
	while(n--)
	{
		cin>>val;
		insert(val,r);
	}
	function<int(TreeNode*)> h=[&h](TreeNode *r){return r==NULL?0:max(h(r->left),h(r->right))+1;};
	int lowest=h(r);
	int n1=0,n2=0;
	solve(r,1,lowest,n1,n2);
	printf("%d + %d = %d",n1,n2,n1+n2);
	return 0;
}
