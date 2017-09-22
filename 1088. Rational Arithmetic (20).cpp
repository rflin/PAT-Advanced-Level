#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
long int a1,b1,a2,b2,a,b;
long int gcd(long int a,long int b)
{
    if(b==0) return a;
    long int r;
    while((r=a%b)) a=b,b=r;
    return b;
}
void simplify(long int &a,long int &b)
{
    long int k=gcd(abs(a),b);
    a/=k;b/=k;
}
void disRA(long int a,long int b)
{
    if(b==0)
    {
        printf("Inf");
        return;
    }
    if(a==0)
    {
        printf("0");
        return;
    }
    long int sg=(a<0)?-1:1;
    a*=sg;
    long int k=a/b;
    a%=b;
    if(sg==-1) printf("(-");
    if(k) printf("%ld",k);
    if(k&&b!=1) printf(" ");
    if(b!=1) printf("%ld/%ld",a,b);
    if(sg==-1) printf(")");
}
void disEqua(long int a1,long int b1,long int a2,long int b2,long int a,long int b,char op)
{
    disRA(a1,b1);
    printf(" %c ",op);
    disRA(a2,b2);
    printf(" = ");
    disRA(a,b);
    printf("\n");
}
void addition()
{
    a=a1*b2+a2*b1;
    b=b1*b2;
    simplify(a,b);
    disEqua(a1,b1,a2,b2,a,b,'+');
}
void subtraction()
{
    a=a1*b2-a2*b1;
    b=b1*b2;
    simplify(a,b);
    disEqua(a1,b1,a2,b2,a,b,'-');
}
void multiplication()
{
    a=a1*a2;
    b=b1*b2;
    simplify(a,b);
    disEqua(a1,b1,a2,b2,a,b,'*');
}
void division()
{
    a=a1*b2;
    b=b1*a2;
    if(b<0) b=-b,a=-a;
    simplify(a,b);
    disEqua(a1,b1,a2,b2,a,b,'/');
}
int main()
{
    scanf("%ld/%ld %ld/%ld",&a1,&b1,&a2,&b2);
    simplify(a1,b1);
    simplify(a2,b2);
    addition();
    subtraction();
    multiplication();
    division();
    return 0;
}
