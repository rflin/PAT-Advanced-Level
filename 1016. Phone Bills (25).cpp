#include <bits/stdc++.h>
using namespace std;
struct node
{
	char name[32];
	int month,dd,hh,mm;
	int time;
	bool status;
}s[1024];
int toll[24];
int daytoll=0;
bool cmp(const node &a,const node &b)
{
	int ret=strcmp(a.name,b.name);
	return ret==0?a.time<b.time:ret<0;
}
double cntBills(int sd,int sh,int sm,int ed,int eh,int em)
{
    double sbill=0.0,ebill=0.0;
    sbill+=(sd-1)*60*daytoll;
    ebill+=(ed-1)*60*daytoll;
    for(int i=0;i<sh;++i)
        sbill+=toll[i]*60;
    for(int i=0;i<eh;++i)
        ebill+=toll[i]*60;
    sbill+=sm*toll[sh];
    ebill+=em*toll[eh];
    return (ebill-sbill);
}
int main()
{
	int n;
	for(int i=0;i<24;++i)
	{
		scanf("%d",&toll[i]);
		daytoll+=toll[i];
	}
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		char str[32];
		scanf("%s %d:%d:%d:%d %s",s[i].name,&s[i].month,&s[i].dd,&s[i].hh,&s[i].mm,str);
		s[i].time=s[i].dd*24*60+s[i].hh*60+s[i].mm;
		s[i].status=(strcmp(str,"on-line")==0)?1:0;
	}
	sort(s,s+n,cmp);
	bool tag=true;
	double totalbill=0.0;
	char curname[32]="";
	for(int i=0;i<n;++i)
	{
		int ret=strcmp(curname,s[i].name);
		if(ret!=0)
		{
			if(totalbill)printf("Total amount: $%.2lf\n",totalbill);
			strcpy(curname,s[i].name);
			ret=0;
			tag=true;
			totalbill=0.0;
		}
		if(ret==0&&s[i].status&&strcmp(curname,s[i+1].name)==0&&!s[i+1].status)
		{
			if(tag==true)
			{
				printf("%s %02d\n",s[i].name,s[i].month);
				tag=false;
			}
			double bills=cntBills(s[i].dd,s[i].hh,s[i].mm,s[i+1].dd,s[i+1].hh,s[i+1].mm)/100;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",s[i].dd,s[i].hh,s[i].mm,s[i+1].dd,s[i+1].hh,s[i+1].mm,s[i+1].time-s[i].time,bills);
			totalbill+=bills;
			++i;
		}
	}
	if(totalbill)printf("Total amount: $%.2lf\n",totalbill);
    return 0;
}
