#include <iostream>
#include <vector>
#include <algorithm>
#include <map> 
#include <queue>
#include <string> 
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left,*right;
	TreeNode(int v=0,TreeNode *l=NULL,TreeNode *r=NULL):val(v),left(l),right(r){}
};
int n,k;
int height(TreeNode *r)
{
	return r==NULL?0:max(height(r->left),height(r->right))+1;
}
TreeNode* rRotate(TreeNode *r)
{
	TreeNode *p=r->left;
	r->left=p->right;
	p->right=r;
	return p;
}
TreeNode* lRotate(TreeNode *r)
{
	TreeNode *p=r->right;
	r->right=p->left;
	p->left=r;
	return p;
}
TreeNode* lrRotate(TreeNode *r)
{
	r->left=lRotate(r->left);
	return rRotate(r);
} 
TreeNode* rlRotate(TreeNode *r)
{
	r->right=rRotate(r->right);
	return lRotate(r);
} 
TreeNode* insert(TreeNode *r,int k)
{
	if(r==NULL)
	{
		TreeNode *p=new TreeNode(k);
		return r=p;
	}
	else if(r->val>k)
	{
		r->left=insert(r->left,k);
		if(abs(height(r->left)-height(r->right))>1)
		{
			r=(k>r->left->val)?lrRotate(r):rRotate(r);
		}
	}
	else 
	{
		r->right=insert(r->right,k);
		if(abs(height(r->left)-height(r->right))>1)
		{
			r=(k>r->right->val)?lRotate(r):rlRotate(r);
		}
	}
	return r;
}
bool levtra(TreeNode *r)
{
	bool ret=true;
	int w=0;
	queue<TreeNode*> q;
	q.push(r);
	while(!q.empty())
	{
		TreeNode *s=q.front();
		q.pop();
		if(s)
		{
			++w==n?cout<<s->val:cout<<s->val<<" ";
			q.push(s->left);
			q.push(s->right);
		}
		else break;
	}
	if(w<n) ret=false; 
	while(!q.empty())
	{
		TreeNode *s=q.front();
		q.pop();
		if(s)
		{
			++w==n?cout<<s->val:cout<<s->val<<" ";
			q.push(s->left);
			q.push(s->right);
		}
	}
	return ret;
}
int main()
{
    TreeNode *r=NULL;
    cin>>n;
    for(int i=0;i<n;++i)
    {
    	cin>>k;
    	r=insert(r,k);
	}
	levtra(r)?cout<<"\nYES":cout<<"\nNO";
    return 0;
}
