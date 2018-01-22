/*
题目地址：https://www.patest.cn/contests/pat-a-practise/1007

作为一道经典的题目，这里列出三种解法

方法一，暴力求解，嵌套两次循环，复杂度（o(n^2)）

```
#include <bits/stdc++.h>
using namespace std;
int maxsum=0x80000000,L,R;
void maxSubseqSum(vector<int> &nums)
{
	int n=nums.size();
	for(int i=0;i<n;++i)
	{
		int cursum=0;
		for(int j=i;j<n;++j)
		{
			cursum+=nums[j];
			if(cursum>maxsum)
			{
				maxsum=cursum;
				L=i;
				R=j;
			}
		}
	}
}
int main()
{
	vector<int> nums;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int x;
		scanf("%d",&x);
		nums.push_back(x);
	}
	maxSubseqSum(nums);
	if(maxsum<0)
	{
		maxsum=0;
		L=0;R=nums.size()-1;
	}
	printf("%d %d %d\n",maxsum,nums[L],nums[R]);
	return 0;
}
```

方法二，分治求解，复杂度（o(nlogn)）

```
#include <bits/stdc++.h>
using namespace std;
struct node
{
	int left,right;
	int sum;
	node(int l,int r,int s):left(l),right(r),sum(s){}
};
node maxval(const node &a,const node &b)
{
	if(a.sum>b.sum||(a.sum==b.sum&&a.left<b.left))
		return a;
	return b;
}
node crossSubseqSum(vector<int> &nums,int left,int right,int mid)
{
	int lmax=0x80000000,rmax=0x80000000;
	int sum=0,l,r;
	for(int i=mid;i>=left;--i)
	{
		sum+=nums[i];
		if(sum>lmax)
		{
			lmax=sum;
			l=i;
		}
	}
	sum=0;
	for(int i=mid+1;i<=right;++i)
	{
		sum+=nums[i];
		if(sum>rmax)
		{
			rmax=sum;
			r=i;
		}
	}
	return node(l,r,lmax+rmax);
}
node maxSubseqSum(vector<int> &nums,int left,int right)
{
	if(left==right) return node(left,right,nums[left]);
	int mid=(left+right)/2;
	node l=maxSubseqSum(nums,left,mid);
	node r=maxSubseqSum(nums,mid+1,right);
	node m=crossSubseqSum(nums,left,right,mid);
	return maxval(maxval(l,r),m);
}
int main()
{
	vector<int> nums;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int x;
		scanf("%d",&x);
		nums.push_back(x);
	}
	node ret=maxSubseqSum(nums,0,nums.size()-1);
	if(ret.sum<0)
	{
		ret.sum=0;
		ret.left=0;
		ret.right=nums.size()-1;
	}
	printf("%d %d %d\n",ret.sum,nums[ret.left],nums[ret.right]);
	return 0;
}
```

方法三：在线处理，复杂度（o(n)）
*/

