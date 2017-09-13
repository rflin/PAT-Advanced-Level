#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n; 
vector<int> p,v;
void nextInsertionseq()
{
	int i=1;
	while(i<n&&v[i]<=v[i+1]) ++i;
	int temp=v[i+1];
	while(temp<v[i]) v[i+1]=v[i],--i;
	v[i+1]=temp;
	for(int i=1;i<=n;++i) i==n?cout<<v[i]:cout<<v[i]<<" ";
}
void nextHeapseq()
{
	int root=v[1],i=1;
	while(i<=n&&v[i]<=root) ++i;
	swap(v[1],v[--i]);
	int temp=v[1],parent=1;
	while(2*parent<i)
	{
		int child=parent*2;
		if(child<i-1&&v[child]<v[child+1])++child;
		if(temp<v[child]) v[parent]=v[child];
		else break;
		parent=child;
	}
	v[parent]=temp;
	for(int i=1;i<=n;++i) i==n?cout<<v[i]:cout<<v[i]<<" ";
}
int main(int argc, char const *argv[])
{
	cin>>n;
	v.resize(n+1);
	p.resize(n+1);
	for(int i=1;i<=n;++i) cin>>p[i];
	for(int i=1;i<=n;++i) cin>>v[i];
	if(v[1]<v[2]) cout<<"Insertion Sort\n",nextInsertionseq();
	else cout<<"Heap Sort\n",nextHeapseq();
	return 0;
}
