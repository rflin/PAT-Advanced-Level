#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct node
{
	string name;
	int size;
	node(string str,int a):name(str),size(a){}
	bool operator<(const node &x)
	{
		return name<x.name;
	}
};

map<string,int> nametoidx;
map<int,string> idxtoname;
vector<vector<int>> v(10240);
int cnttime[10240];
bool vis[10240];
int n,k,idx=0;
int totaltime,cnt,head,maxtime;
vector<node> ans;

void dfs(int cur)
{
	if(vis[cur]) return;
	vis[cur]=true;
	cnt++;
	totaltime+=cnttime[cur];
	maxtime=maxtime>cnttime[cur]?maxtime:cnttime[head=cur];
	for(auto x:v[cur])
	{
		if(!vis[x]) dfs(x);
	}
}
int main(int argc, char const *argv[])
{
	cin>>n>>k;
	for(int i=0;i<n;++i)
	{
		string str1,str2;
		int idx1,idx2,w;
		cin>>str1>>str2>>w;
		if(nametoidx.count(str1)) idx1=nametoidx[str1];
		else
		{
			idx1=nametoidx[str1]=idx;
			idxtoname[idx++]=str1;
		}
		if(nametoidx.count(str2)) idx2=nametoidx[str2];
		else
		{
			idx2=nametoidx[str2]=idx;
			idxtoname[idx++]=str2;
		}
		v[idx1].push_back(idx2);
		v[idx2].push_back(idx1);
		cnttime[idx1]+=w;
		cnttime[idx2]+=w;
	}
	for(int i=0;i<idx;++i)
	{
		totaltime=0;
		cnt=0;
		maxtime=-1;
		head=-1;
		dfs(i);
		if(cnt>2&&totaltime>2*k) ans.push_back(node(idxtoname[head],cnt));
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(auto x:ans)
		cout<<x.name<<" "<<x.size<<endl;
	return 0;
}
