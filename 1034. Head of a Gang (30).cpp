#include <bits/stdc++.h>
using namespace std;
vector<string> idx2name;
map<string,int> name2idx,result;
vector<int> v[2048];
int n,k,indexs=0,val[2048];
int getidx(string &name){
	if(name2idx.count(name)) return name2idx[name];
	name2idx[name]=indexs++;
	idx2name.push_back(name);
	return indexs-1;
}
void dfs(int u,vector<bool> &visit,int &maxvtx,int &maxval,int &nums,int &sums){
	if(visit[u]) return;
	visit[u]=1;
	++nums;
	sums+=val[u];
	if(val[u]>maxval){
		maxval=val[u];
		maxvtx=u;
	}
	for(int x:v[u]){
		if(!visit[x]) dfs(x,visit,maxvtx,maxval,nums,sums);
	}
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<n;++i)
	{
		string a,b;
		int w,idxa,idxb;
		cin>>a>>b>>w;
		idxa=getidx(a);
		idxb=getidx(b);
		v[idxa].push_back(idxb);
		v[idxb].push_back(idxa);
		val[idxa]+=w,val[idxb]+=w;
	}
	vector<bool> visit(indexs,0);
	for(int i=0;i<indexs;++i){
		int maxvtx=i,maxval=val[i],nums=0,sums=0;
		dfs(i,visit,maxvtx,maxval,nums,sums);
		if(nums>2&&sums>2*k){
			result[idx2name[maxvtx]]=nums;
		}
	}
	cout<<result.size()<<endl;
	for(auto &x:result){
		cout<<x.first<<" "<<x.second<<endl;
	}
	return 0;
}
