#include <bits/stdc++.h>
using namespace std;
struct node
{
	int rank;
	string school;
	int tws,ns;
	node(int r,string s,int t,int n):rank(r),school(s),tws(t),ns(n){}
};
map<string,pair<int,double>> mp;
double cptscore(char x,double score)
{
	if(x=='B') score/=1.5;
	if(x=='T') score*=1.5;
	return score;
}
void lr(char school[],int len)
{
	for(int i=0;i<len;++i){
		if(isupper(school[i])){
			school[i]=tolower(school[i]);
		}
	}
}
bool cmp(const node &a,const node &b)
{
	if(a.tws!=b.tws)
		return a.tws>b.tws;
	return a.ns==b.ns?a.school<b.school:a.ns<b.ns;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		char id[12],school[12];
		double score;
		scanf("%s %lf %s",id,&score,school);
		score=cptscore(id[0],score);
		lr(school,strlen(school));
		auto &res=mp[school];
		res.first++;
		res.second+=score;
	}
	vector<node> v;
	for(auto &x:mp){
		string school=x.first;
		int ns=x.second.first,tws=x.second.second;
		v.push_back(node(0,school,tws,ns));
	}
	sort(v.begin(),v.end(),cmp);
	int l=v.size();
	v[0].rank=1;
	for(int i=1;i<l;++i){
		v[i].rank=(v[i].tws==v[i-1].tws)?v[i-1].rank:i+1;
	}
	printf("%d\n",l);
	for(node &x:v){
		printf("%d %s %d %d\n",x.rank,x.school.c_str(),x.tws,x.ns);
	}
	return 0;
}
