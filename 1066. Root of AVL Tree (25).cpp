#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left,*right;
	TreeNode(int v=0,TreeNode *l=NULL,TreeNode *r=NULL):val(v),left(l),right(r){}
};
int height(TreeNode *r)
{
	return r==NULL?0:max(height(r->left),height(r->right))+1;
}
TreeNode *lRotate(TreeNode *r)
{
	TreeNode *p=r->right;
	r->right=p->left;
	p->left=r;
	return p;
}
TreeNode *rRotate(TreeNode *r)
{
	TreeNode *p=r->left;
	r->left=p->right;
	p->right=r;
	return p;
}
TreeNode *lrRotate(TreeNode *r)
{
	r->left=lRotate(r->left);
	return rRotate(r);
}
TreeNode *rlRotate(TreeNode *r)
{
	r->right=rRotate(r->right);
	return lRotate(r);
}
TreeNode * insert(TreeNode* r,int val)
{
	if(r==NULL) return new TreeNode(val);
	else if(r->val<val)
	{
		r->right=insert(r->right,val);
		if(abs(height(r->left)-height(r->right))>=2)
		{
			r=(r->right->val<val)?lRotate(r):rlRotate(r);
		}
	}
	else
	{
		r->left=insert(r->left,val);
		if(abs(height(r->left)-height(r->right))>=2)
		{
			r=(r->left->val<val)?lrRotate(r):rRotate(r);
		}
	}
	return r;
}
int main()
{
	int n,val;
	TreeNode *r=NULL;
	cin>>n;
	while(n--)
	{
		cin>>val;
		r=insert(r,val);
	}
	cout<<r->val;
	return 0;
}
