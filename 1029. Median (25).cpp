#include <iostream>
#include <cstdio>
using namespace std;
long int a[10000000],b[10000000];
int main()
{
	long int an,bn;
	scanf("%ld",&an);
	for(long int i=0;i<an;++i)
		scanf("%ld",&a[i]);
	scanf("%ld",&bn);
	for(long int i=0;i<bn;++i)
		scanf("%ld",&b[i]);
	long int mid=(an+bn+1)/2,cnt=0,i=0,j=0,val=-1;
	while(i<an&&j<bn&&cnt<mid)
	{
		a[i]<b[j]?val=a[i++]:val=b[j++];
		++cnt;
	} 
	if(cnt==mid) printf("%ld\n",val);
	else
	{
		if(i<an) while(cnt<mid) ++cnt,val=a[i++];
		else while(cnt<mid) ++cnt,val=b[j++];
		printf("%ld\n",val);
	}
	return 0;
}
