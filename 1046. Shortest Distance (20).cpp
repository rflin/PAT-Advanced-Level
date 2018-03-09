#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,sum=0,x,k;
	scanf("%d",&n);
	vector<int> val(n+1,0);
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		sum+=x;
		val[i]=sum;
	}
	scanf("%d",&k);
	while(k--){
		int i,j;
		scanf("%d %d",&i,&j);
		if(i>j) swap(i,j);
		printf("%d\n",min(val[j-1]-val[i-1],sum-val[j-1]+val[i-1]));
	}
	return 0;
}
