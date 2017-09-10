#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int n;
double sum,v;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%lf",&v);
		sum+=v*(n-i)*(i+1);
	}
	printf("%.2lf",sum);
	return 0;
}
/*
1
1 2
1 2 3
1 2 3 4
2 
2 3
2 3 4
3
3 4
4
*/
