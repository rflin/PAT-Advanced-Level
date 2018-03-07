#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left,*right;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};
int height(TreeNode *r)
{
	return r==NULL?0:max(height(r->left),height(r->right))+1;
}
TreeNode* lRotate(TreeNode *r)
{
	TreeNode *p=r->right;
	r->right=p->left;
	p->left=r;
	return p;
}
TreeNode* rRotate(TreeNode *r)
{
	TreeNode *p=r->left;
	r->left=p->right;
	p->right=r;
	return  p;
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
TreeNode* insert(int val,TreeNode *r)
{
	if(r==NULL) return new TreeNode(val);
	if(r->val<val){
		r->right=insert(val,r->right);
		if(abs(height(r->left)-height(r->right))>1){
			r=(r->right->val<val)?lRotate(r):rlRotate(r);
		}
	}
	else{
		r->left=insert(val,r->left);
		if(abs(height(r->left)-height(r->right))>1){
			r=(r->left->val>val)?rRotate(r):lrRotate(r);
		}
	}
	return r;
}
void levtra(TreeNode *r,int w,bool &iscbt)
{
	queue<TreeNode*> q;
	q.push(r);
	while(!q.empty()){
		TreeNode *s=q.front();
		q.pop();
		if(s){
			--w?printf("%d ",s->val):printf("%d\n",s->val);;
			q.push(s->left);
			q.push(s->right);
		}
		else break;
	}
	iscbt=w?0:1;
	while(!q.empty()){
		TreeNode *s=q.front();
		q.pop();
		if(s){
			--w?printf("%d ",s->val):printf("%d\n",s->val);;
			q.push(s->left);
			q.push(s->right);
		}
	}
}
int main()
{
	TreeNode *r=NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		int val;
		scanf("%d",&val);
		r=insert(val,r);
	}
	bool iscbt=0;
	levtra(r,n,iscbt);
	iscbt?printf("YES\n"):printf("NO\n");
	return 0;
}
