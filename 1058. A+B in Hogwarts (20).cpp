#include<stdio.h>
int main()
{
    int G,S,K;
    int aG,aS,aK,bG,bS,bK;
    int addS=0,addG=0;
    scanf("%d.%d.%d %d.%d.%d",&aG,&aS,&aK,&bG,&bS,&bK);
    K=aK+bK;
    addS=K/29;
    K%=29;
    S=aS+bS+addS;
    addG=S/17;
    S%=17;
    G=aG+bG+addG;
    printf("%d.%d.%d",G,S,K);
}
