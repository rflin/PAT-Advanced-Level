#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <map> 
using namespace std;
vector<int> dsv,guests;
map<int,int> couples;
map<int,bool> ishere;
int main()
{
    int n,m;
    cin>>n;
    for(int i=0;i<n;++i)
    {
    	int id1,id2;
    	cin>>id1>>id2;
    	ishere[id1]=false;
    	ishere[id2]=false;
    	couples[id1]=id2;
    	couples[id2]=id1;
	}
	cin>>m;
	guests.resize(m);
	for(int i=0;i<m;++i)
	{
		cin>>guests[i];
		ishere[guests[i]]=true;
	} 
	for(auto id:guests)
	{
		if(!(couples.count(id)&&ishere[couples[id]])) dsv.push_back(id);
	}
	sort(dsv.begin(),dsv.end());
	cout<<dsv.size()<<endl;
	for(unsigned int i=0;i<dsv.size();++i) i==dsv.size()-1?printf("%05d",dsv[i]):printf("%05d ",dsv[i]);
    return 0;
}
