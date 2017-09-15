#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[1024];
int maxlen;
void lss(char a[],int i,int j,int n)
{
	while(i>=0&&j<n&&a[i]==a[j])--i,++j;
	maxlen=max(maxlen,j-i-1);
}
void LongestSymmetricStr(char str[],int n)
{
	for(int i=0;i<n;++i)
	{
		lss(str,i,i,n);
		lss(str,i,i+1,n);
	}
}
int main()
{
	gets(str);
	LongestSymmetricStr(str,strlen(str));
	cout<<maxlen;
	return 0;
}
