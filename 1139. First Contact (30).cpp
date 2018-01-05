/*
需要注意的点：
1、四位id，诸如0001也是正确的，所以最后需要printf格式化输出
2、四位id，诸如-0000也是可以的，所以读取时，需要用字符串读取，而不是整数 
*/
#include <bits/stdc++.h>
using namespace std;

struct friends
{
	int x,y;
	friends(int a,int b):x(a),y(b){}
};
vector<int> v[10000];
bool matrix[10000][10000];
void search(vector<friends> &ans,int a,int b)
{
	for(int x:v[a])
	{
		for(int y:v[b])
		{
			if(x==y||x==b||y==a)continue;//same gender circumstance
			if(matrix[x][y])ans.push_back(friends(x,y));
		}
	}
}
bool cmp(const friends &a,const friends &b)
{
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
int main()
{
	//freopen("1.txt","r",stdin);
	int n,m,k;
	cin>>n>>m;
	for(int i=0;i<m;++i)
	{
		string a,b;
		cin>>a>>b;
		if(a.size()==b.size())//same gender
		{
			v[abs(stoi(a))].push_back(abs(stoi(b)));
			v[abs(stoi(b))].push_back(abs(stoi(a)));
		}
		matrix[abs(stoi(a))][abs(stoi(b))]=matrix[abs(stoi(b))][abs(stoi(a))]=true;//are friends
	}
	cin>>k;
	while(k--)
	{
		int a,b;
		cin>>a>>b;
		vector<friends> ans;//collect answer
		search(ans,abs(a),abs(b));
		sort(ans.begin(),ans.end(),cmp);
		cout<<ans.size()<<endl;
		for(auto w:ans)
			printf("%04d %04d\n",w.x,w.y);
	}
	return 0;
}
