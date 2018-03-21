#include <bits/stdc++.h>
using namespace std;
vector<int> A,v;
int m,n;
void postra(int i)
{
	if(i<=n){
		postra(2*i);
		postra(2*i+1);
		v.push_back(A[i]);
	}
}
bool isMaxHeap()
{
	int i=n/2;
	while(i){
		int child=2*i;
		if(child!=n&&A[child]<A[child+1]) ++child;
		if(A[i]<A[child]) return 0;
		--i;
	}
	return 1;
}
bool isMinHeap()
{
	int i=n/2;
	while(i){
		int child=2*i;
		if(child!=n&&A[child]>A[child+1]) ++child;
		if(A[i]>A[child]) return 0;
		--i;
	}
	return 1;
}
int main()
{
	scanf("%d %d",&m,&n);
	A=vector<int>(n+1);
	while(m--){
		for(int i=1;i<=n;++i)
			scanf("%d",&A[i]);
		v.clear();
		if(isMaxHeap()) printf("Max Heap\n");
		else if(isMinHeap()) printf("Min Heap\n");
		else printf("Not Heap\n");
		postra(1);
		int w=v.size();
		for(int x:v)
			--w?printf("%d ",x):printf("%d\n",x);;
	}
	return 0;
}
