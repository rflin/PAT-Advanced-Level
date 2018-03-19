#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left,*right;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};
int pre[10000+32],ino[10000+32];
TreeNode * build(int preL,int preR,int inoL,int inoR)
{
	if(preL>preR) return NULL;
	int e=pre[preL],idx=inoL;
	while(idx<=inoR&&e!=ino[idx]) ++idx;
	TreeNode *r=new TreeNode(e);
	r->left=build(preL+1,preL+1+idx-1-inoL,inoL,idx-1);
	r->right=build(preR+idx+1-inoR,preR,idx+1,inoR);
	return r;
}
TreeNode *search(TreeNode *r,int e)
{
	while(r){
		if(e<r->val) r=r->left;
		else if(e>r->val) r=r->right;
		else return r;
	}
	return r;
}
TreeNode *LCA(TreeNode *r,TreeNode *px,TreeNode *py)
{
	while((r->val-px->val)*(r->val-py->val)>0){
		r=(r->val<px->val)?r->right:r->left;
	}
	return r;
}
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;++i){
		scanf("%d",pre+i);
		ino[i]=pre[i];
	}
	sort(ino,ino+n);
	TreeNode *r=build(0,n-1,0,n-1);
	while(m--){
		int x,y;
		scanf("%d %d",&x,&y);
		TreeNode *px=search(r,x),*py=search(r,y);
		if(!px&&!py) printf("ERROR: %d and %d are not found.\n",x,y);
		else if(!(px&&py)) printf("ERROR: %d is not found.\n",px?y:x);
		else{
			TreeNode *res=LCA(r,px,py);
			if(res==px) printf("%d is an ancestor of %d.\n",px->val,py->val);
			else if(res==py) printf("%d is an ancestor of %d.\n",py->val,px->val);
			else printf("LCA of %d and %d is %d.\n",px->val,py->val,res->val);
		}
	}
	return 0;
}
