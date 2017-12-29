#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string maleinfo="Absent",femaleinfo="Absent";
	int maxscore=-1,minscore=101;
	cin>>n;
	while(n--)
	{
		string name,gender,id;
		int score;
		cin>>name>>gender>>id>>score;
		if(gender=="F"&&score>maxscore)
		{
			maxscore=score;
			femaleinfo=name+" "+id;
		}
		if(gender=="M"&&score<minscore)
		{
			minscore=score;
			maleinfo=name+" "+id;
		}
	}
	cout<<femaleinfo<<endl<<maleinfo<<endl;
	if(minscore!=101&&maxscore!=-1)
		cout<<maxscore-minscore<<endl;
	else
		cout<<"NA"<<endl;
	return 0;
}
