#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 80+1
struct book
{
    char id[8];
    char title[N];
    char author[N];
    char keywords[100];
    char publisher[N];
    char pubyear[5];
}book[10001];
int comp(const void*a,const void*b)
{
    struct book *p=(struct book*)a,*q=(struct book*)b;
    return strcmp(p->id,q->id);
}
void TitleSearch(char s[],int n)
{
    int check=0,i=0;
    while(i<n)
    {
        if(strcmp(book[i].title,s)==0)
        {
            check=1;printf("%s\n",book[i].id);
        }
        ++i;
    }
    if(!check)printf("Not Found\n");
}
void AuthorSearch(char s[],int n)
{
    int check=0,i=0;
    while(i<n)
    {
        if(strcmp(book[i].author,s)==0)
        {
            check=1;printf("%s\n",book[i].id);
        }
        ++i;
    }
    if(!check)printf("Not Found\n");
}
void KeySearch(char s[],int n)
{
    int check=0,i=0;
    while(i<n)
    {
        if(strstr(book[i].keywords,s))
        {
            check=1;printf("%s\n",book[i].id);
        }
        ++i;
    }
    if(!check)printf("Not Found\n");
}
void PublisherSearch(char s[],int n)
{
    int check=0,i=0;
    while(i<n)
    {
        if(strcmp(book[i].publisher,s)==0)
        {
            check=1;printf("%s\n",book[i].id);
        }
        ++i;
    }
    if(!check)printf("Not Found\n");
}
void PubYearSearch(char s[],int n)
{
    int check=0,i=0;
    while(i<n)
    {
        if(strcmp(book[i].pubyear,s)==0)
        {
            check=1;printf("%s\n",book[i].id);
        }
        ++i;
    }
    if(!check)printf("Not Found\n");
}
int main()
{
    int m,i=0,n;
    scanf("%d",&n);
    getchar();
    while(i<n)
    {
        gets(book[i].id);
        gets(book[i].title);
        gets(book[i].author);
        gets(book[i].keywords);
        gets(book[i].publisher);
        gets(book[i].pubyear);
        ++i;
    }
    qsort(book,n,sizeof(struct book),comp);
    scanf("%d",&m);
    while(m--)
    {
        int sign;
        char s[100];
        scanf("%d: ",&sign);
        gets(s);
        printf("%d: %s\n",sign,s);
        switch(sign)
        {
            case 1:TitleSearch(s,n);break;
            case 2:AuthorSearch(s,n);break;
            case 3:KeySearch(s,n);break;
            case 4:PublisherSearch(s,n);break;
            case 5:PubYearSearch(s,n);break;
        }
    }
    return 0;
}
