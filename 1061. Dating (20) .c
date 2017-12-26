#include <stdio.h>
#include <string.h>
#include <ctype.h>
int weekValid(char c)
{
    return c>='A'&&c<='G'?1:0;
}
int hourValid(char c)
{
    return isdigit(c)||(c>='A'&&c<='N')?1:0;
}
void weekFind(char c)
{
    switch(c){
        case 'A':printf("MON ");break;
        case 'B':printf("TUE ");break;
        case 'C':printf("WED ");break;
        case 'D':printf("THU ");break;
        case 'E':printf("FRI ");break;
        case 'F':printf("SAT ");break;
        case 'G':printf("SUN ");break;
    }
}
int hourFind(char c)
{
    return isdigit(c)?c-'0':10+c-'A';
}
int main()
{
    char s1[64],s2[64],s3[64],s4[64];
    scanf("%s\n%s",s1,s2);
    int len1=strlen(s1),len2=strlen(s2);
    int i=0;
    while(i<len1&&i<len2)
    {
        if(s1[i]==s2[i]&&weekValid(s1[i])) break;
        ++i;
    }
    weekFind(s1[i++]);
    while(i<len1&&i<len2)
    {
        if(s1[i]==s2[i]&&hourValid(s1[i])) break;
        ++i;
    }
    int h=hourFind(s1[i]);
    scanf("%s\n%s",s3,s4);
    int len3=strlen(s3),len4=strlen(s4);
    i=0;
    while(i<len3&&i<len4)
    {
        if(s3[i]==s4[i]&&isalpha(s3[i])) break;
        ++i;
    }
    int m=i;
    printf("%02d:%02d\n",h,m);
    return 0;
}
