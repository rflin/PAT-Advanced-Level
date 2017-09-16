#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main()
{
	int n,ft=24*3600+1,lt=-1;
	char first[32],last[32];
	scanf("%d\n",&n);
	for(int i=0;i<n;++i)
	{
		char s[32];
		int h1,m1,s1,h2,m2,s2;
		scanf("%s %d:%d:%d %d:%d:%d",s,&h1,&m1,&s1,&h2,&m2,&s2);
		int t1=h1*3600+m1*60+s1,t2=h2*3600+m2*60+s2;
		if(t1<ft) ft=t1,strcpy(first,s);
		if(t2>lt) lt=t2,strcpy(last,s);
	}
	printf("%s %s",first,last);
	return 0;
}
