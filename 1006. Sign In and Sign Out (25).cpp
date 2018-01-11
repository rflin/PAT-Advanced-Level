#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	string fname,lname,fst("24:00:00"),lst("00:00:00");
	cin>>m;
	while(m--)
	{
		string name,intime,outtime;
		cin>>name>>intime>>outtime;
		if(intime<=fst)
		{
			fst=intime;
			fname=name;
		}
		if(outtime>=lst)
		{
			lst=outtime;
			lname=name;
		}
	}
	cout<<fname<<" "<<lname<<endl;
	return 0;
}
