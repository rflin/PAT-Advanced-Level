#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
vector<int> pre,ino;
struct TreeNode
{
	int val;
	TreeNode *left,*right;
	TreeNode(int v=0,TreeNode *l=NULL,TreeNode *r=NULL):val(v),left(l),right(r){}
};
TreeNode *build(vector<int> &pre,vector<int> &ino,int preL,int preR,int inoL,int inoR)
{
	if(preL>preR) return NULL;
	int e=pre[preL],idx=inoL,pdx=preL;
	while(idx<=inoR&&ino[idx]!=e) ++idx,++pdx;
	TreeNode *r=new TreeNode(e);
	r->left=build(pre,ino,preL+1,pdx,inoL,idx-1);
	r->right=build(pre,ino,pdx+1,preR,idx+1,inoR);
	return r;
}
bool help(TreeNode *r)
{
	if(!r||r->val>0) return 1;//为空(NULL为黑)或者节点为黑
	return 0;
}
bool checkrednode(TreeNode *r)
{
	if(r->val<0) return help(r->left)&&help(r->right);
	return true;
}
int isrbTree(TreeNode *r,bool &ret,bool &res)
{
	if(r)
	{
		int lbc=isrbTree(r->left,ret,res);//左边黑色节点个数
		int rbc=isrbTree(r->right,ret,res);//右边黑色节点个数
		if(!checkrednode(r)) res=0;//红色节点左右子树必须为黑，否则不合法
		if(lbc!=rbc) ret=0;//左右不等，不合法
		return r->val>0?lbc+1:lbc;
	}
	return 1;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int m;
		cin>>m;
		pre.resize(m);
		ino.resize(m);
		for(int i=0;i<m;++i) cin>>pre[i];
		ino=pre;
		sort(ino.begin(),ino.end(),[](const int &a,const int &b){return abs(a)<abs(b);});//按绝对值从小到大排序
		TreeNode *r=build(pre,ino,0,m-1,0,m-1);//构建二叉树
		bool ret=1,res=1;
		isrbTree(r,ret,res);//是否是红黑树
		r->val>0&&res&&ret?cout<<"Yes\n":cout<<"No\n";//根节点必须为黑(第二个测试点)
	}
	return 0;
}
