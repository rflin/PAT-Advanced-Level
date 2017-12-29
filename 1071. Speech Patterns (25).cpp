#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    map<string,int> word;
    string s,curword,ans;
    int cnt=0;
    getline(cin,s);
    int index=0,slen=s.size();
    s[slen++]='.';
    for(index=0;index!=slen;++index)
    {
        while((isalpha(s[index])||isdigit(s[index]))&&index!=slen)
        {
            if(isalpha(s[index])&&isupper(s[index]))
                s[index]=tolower(s[index]);
            curword+=s[index];++index;
        }
        if(curword.size())
        {
            word[curword]++;
            if(word[curword]>cnt)
            {
                cnt=word[curword];
                ans=curword;
            }
        }
        curword.erase();
    }
    cout<<ans<<" "<<cnt;
    return 0;
}
