#include <stdio.h>
struct node
{
	char data;
	int next;
}node[100000];
int GetListLength(int head)
{
	int cnt=0,p=head;
	while(p!=-1)
	{
		++cnt;
		p=node[p].next;
	}
	return cnt;
}
void update(int *h,int cnt)
{
	while(cnt--) *h=node[*h].next;
}
int main()
{
	int xhead,yhead,n;
	scanf("%d %d %d",&xhead,&yhead,&n);
	int x=xhead,y=yhead;
	for(int i=0;i<n;++i)
	{
		int add,next;
		char data;
		scanf("%d %c %d",&add,&data,&next);
		node[add].data=data;
		node[add].next=next;
	}
	int lenx=GetListLength(xhead);
	int leny=GetListLength(yhead);
	lenx<leny?update(&y,leny-lenx):update(&x,lenx-leny);
	while(x!=y)
	{
		x=node[x].next;
		y=node[y].next;
	}
	if(x==-1)printf("-1");
	else printf("%05d",x);
	return 0;
}
