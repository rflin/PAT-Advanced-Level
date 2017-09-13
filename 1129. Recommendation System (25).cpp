/*
题目地址：https://www.patest.cn/contests/pat-a-practise/1129
思路：stl的set用法
*/
#include <iostream>
#include <vector>
#include <set> 
#include <unordered_map>
#include <algorithm>
using namespace std;
struct node
{
	int idx,cnt;
	node(int x,int y):idx(x),cnt(y){}
	bool operator <(const node &x)const
	{
		if(cnt!=x.cnt) return cnt>x.cnt;
		return idx<x.idx;
	}
};
int main(int argc, char const *argv[])
{
	int n,k;
	set<node> mset;
	unordered_map<int,int> cnt;
	cin>>n>>k;
	for(int i=0;i<n;++i)
	{
		int idx;
		cin>>idx;
		if(i)
		{
			cout<<idx<<":";
			int w=0;
			for(auto it=mset.begin();it!=mset.end()&&++w<=k;++it) cout<<" "<<it->idx;
			cout<<endl;
		}
		auto it=mset.find(node(idx,cnt[idx]));
		if(it!=mset.end()) mset.erase(it);
		mset.insert(node(idx,++cnt[idx]));
	} 
	return 0;
}
