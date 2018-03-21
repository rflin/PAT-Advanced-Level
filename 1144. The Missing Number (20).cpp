#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,val;
	vector<int> A;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&val);
		if(val>0) A.push_back(val);
	}
	n=A.size();
	for(int i=0;i<n;++i){
		while(A[i]<=n&&A[i]!=A[A[i]-1]) swap(A[i],A[A[i]-1]);
	}
	for(int i=0;i<n;++i){
		if(A[i]!=i+1){
			printf("%d\n",i+1);
			return 0;
		}
	}
	printf("%d\n",n+1);
	return 0;
}
