#include <bits/stdc++.h>
using namespace std;
bool islegal(string &s){
    int inpcnt,dotcnt=0,deccnt=0;
    for(size_t i=0;i<s.size();++i){
        if(i==0&&s[i]=='-') continue;
        if(isdigit(s[i])&&dotcnt==0){
            ++inpcnt;continue;
        }
        if(isdigit(s[i])&&dotcnt==1&&deccnt<2){
            ++deccnt;continue;
        }
        if(s[i]=='.'&&inpcnt>0&&dotcnt==0){
            ++dotcnt;continue;
        }
        return false;
    }
    return true;
}
int main(){
    double sum=0.0;
    int n,cnt=0;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        if(islegal(str)){
            double num=stod(str);
            if(num>=-1000&&num<=1000){
                sum+=num;
                cnt++;
            }
            else printf("ERROR: %s is not a legal number\n",str.c_str());
        }
        else printf("ERROR: %s is not a legal number\n",str.c_str());
    }
    if(cnt>1) printf("The average of %d numbers is %.2lf\n",cnt,sum/cnt);
    else if(cnt==1) printf("The average of 1 number is %.2lf\n",sum);
    else printf("The average of 0 numbers is Undefined\n");
}
