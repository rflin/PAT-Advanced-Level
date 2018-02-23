#include <bits/stdc++.h>
using namespace std;
int mark[128],isprt[128];
int main()
{
	string instr,outstr;
	cin>>instr>>outstr;
	for(char &x:outstr)
	{
		if(isalpha(x)) x=toupper(x);
		mark[x-'\0']=1;
	}
	for(char &x:instr)
	{
		if(isalpha(x)) x=toupper(x);
		if(!mark[x-'\0']&&!isprt[x-'\0']) putchar(x),isprt[x-'\0']=1;
	}
	return 0;
}
