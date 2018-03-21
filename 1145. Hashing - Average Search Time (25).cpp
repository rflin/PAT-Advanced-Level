#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int tsize,n,m;
bool isprime(int n)
{
	if(n<2) return 0;
	for(int i=2;i*i<=n;++i){
		if(n%i==0) return 0;
	}
	return 1;
}
int getAddress(int val)
{
	return val%tsize;
}
void insert(int val)
{
	int i=0;
	while(i<tsize){
		int address=getAddress(val+i*i);
		if(v[address]==0){
			v[address]=val;
			return;
		}
		++i;
	}
	printf("%d cannot be inserted.\n",val);
}
int search(int val)
{
	int i=0,cnt=0;
	while(i<tsize){
		++cnt;
		int address=getAddress(val+i*i);
		if(v[address]==val||v[address]==0) return cnt;
		++i;
	}
	return cnt+1;
}
int main()
{
	scanf("%d %d %d",&tsize,&n,&m);
	while(!isprime(tsize)) ++tsize;
	v=vector<int>(tsize);
	for(int i=0;i<n;++i){
		int val;
		scanf("%d",&val);
		insert(val);
	}
	double sum=0.0;
	for(int i=0;i<m;++i){
		int val;
		scanf("%d",&val);
		sum+=search(val);
	}
	printf("%.1lf\n",sum/m);
	return 0;
}
