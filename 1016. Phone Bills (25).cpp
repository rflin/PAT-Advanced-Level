#include <bits/stdc++.h>

using namespace std;
struct node{
    int m, d, hh, mm;
    int t;
    bool online;
};

int toll[24], n, daytoll;

map<string, vector<node>> mp;

bool cmp(const node &a, const node &b){
    return a.t < b.t;
}
double mkbill(node &a){
    int d = a.d, h = a.hh, m = a.mm;
    double bill = (d - 1) * 60 * daytoll;
    for(int i = 0; i < h; ++i){
        bill += 60 * toll[i];
    }
    bill += m * toll[h];
    return bill / 100;
}

void sol(const char name[], vector<node> &v){
    bool flag = true, tag = false;
    int sz = v.size(), i = 0;
    double sum = 0.0;
    while(i < sz){
        if(i + 1 < sz && v[i].online && !v[i + 1].online){
            tag = true;
            if(flag){
                printf("%s %02d\n", name, v[0].m);
                flag = false;
            }
            int j = i + 1;
            double billcnts = mkbill(v[j]) - mkbill(v[i]);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", v[i].d, v[i].hh, v[i].mm, v[j].d, v[j].hh, v[j].mm, v[j].t - v[i].t, billcnts);
            sum += billcnts;
            i += 2;
        }
        else ++i;
    }
    if(tag) printf("Total amount: $%.2f\n", sum);
}

int main()
{
    for(int i = 0; i < 24; ++i){
        scanf("%d", toll + i);
        daytoll += toll[i];
    }
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        char name[24], status[24];
        node x;
        scanf("%s %d:%d:%d:%d %s", name, &x.m, &x.d, &x.hh, &x.mm, status);
        x.t = (x.d - 1) * 24 * 60 + x.hh * 60 + x.mm;
        x.online = status[1] == 'n';
        mp[string(name)].push_back(x);
    }
    for(auto &x: mp){
        sort(x.second.begin(), x.second.end(), cmp);
        sol(x.first.c_str(), x.second);
    }
    return 0;
}
