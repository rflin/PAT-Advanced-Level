#include <bits/stdc++.h>
using namespace std;
vector<char> v={'S','H','C','D','J'};
string val(int Num)
{
	return v[(Num-1)/13]+to_string((Num-1)%13+1);
}
int main()
{
	int times,order[54+1];
	scanf("%d",&times);
	vector<int> cards(54+1);
	for(int i=1;i<=54;++i)
	{
		cards[i]=i;
		cin>>order[i];
	}
	while(times--)
	{
		vector<int> temp(54+1);
		for(int i=1;i<=54;++i)
			temp[order[i]]=cards[i];
		cards=temp;
	}
	for(int i=1;i<54;++i)
		cout<<val(cards[i])<<" ";
	cout<<val(cards[54]);
	return 0;
}
