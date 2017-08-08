#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int matrix[10000+1][10000+1];
void getMandN(int &m,int &n,int num)
{
	int sq=sqrt(num*1.0);
	n=m=sq;
	while(m*n!=num)
	{
		while(m*n<num) ++m;
		if(m*n==num) break;
		--n;
	}
}
int main()
{
	int num,m=1,n=1;
	cin>>num;
	std::vector<int> v;
	for(int i=0;i<num;++i)
	{
		int t;
		cin>>t;
		v.push_back(t);
	}
	sort(v.begin(),v.end(),greater<int>());
	getMandN(m,n,num);
	int i=1,j=1,k=0,layer=0;
	while(k<num)
	{
		while(k<num&&j<=n-layer)matrix[i][j++]=v[k++];
		--j;++i;
		while(k<num&&i<=m-layer)matrix[i++][j]=v[k++];
		--i;--j;
		while(k<num&&j>=1+layer)matrix[i][j--]=v[k++];
		++j;--i;
		while(k<num&&i>=2+layer)matrix[i--][j]=v[k++];
		++i;++j;
		++layer;
	}
	for(int i=1;i<=m;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(j!=n)cout<<matrix[i][j]<<" ";
			else cout<<matrix[i][j]<<endl;
		}
	}
	return 0;
}
