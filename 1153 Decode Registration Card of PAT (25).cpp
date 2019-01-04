#include <bits/stdc++.h>
using namespace std;
struct node{
    char cardnums[16];
    int score;
};
struct vnode{
    int sitenum, cnts;
    vnode(int sn, int ct): sitenum(sn), cnts(ct){}
};
vector<node> vl[26];
pair<int, int> sitecnts[1024];
unordered_map<int, map<int, int>> mp;
bool cmp1(const node &a, const node &b){
    return a.score == b.score ? strcmp(a.cardnums, b.cardnums) < 0 : a.score > b.score;
}
bool cmp2(const vnode &a, const vnode &b){
    return a.cnts == b.cnts ? a.sitenum < b.sitenum : a.cnts > b.cnts;
}
int convert(char str[], int s, int e){
    int res = 0;
    while(s <= e){
        res = res * 10 + str[s++] - '0';
    }
    return res;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i){
        node x;
        scanf("%s %d", x.cardnums, &x.score);
        vl[x.cardnums[0]-'A'].push_back(x);
        int sitenum = convert(x.cardnums, 1, 3);
        sitecnts[sitenum].first++;
        sitecnts[sitenum].second += x.score;
        int date = convert(x.cardnums, 4, 9);
        mp[date][sitenum]++;
    }
    sort(vl['A' - 'A'].begin(), vl['A' - 'A'].end(), cmp1);
    sort(vl['T' - 'A'].begin(), vl['T' - 'A'].end(), cmp1);
    sort(vl['B' - 'A'].begin(), vl['B' - 'A'].end(), cmp1);
    for(int i = 1; i <= m; ++i){
        int type;
        scanf("%d" ,&type);
        printf("Case %d: %d ", i, type);
        if(type == 1){
            char lev;
            scanf(" %c", &lev);
            printf("%c\n", lev);
            if(vl[lev - 'A'].size() == 0) printf("NA\n");
            else{
                for(auto &x : vl[lev - 'A']){
                    printf("%s %d\n", x.cardnums, x.score);
                }
            }
        }else if(type == 2){
            int sitenum;
            scanf("%d", &sitenum);
            printf("%d\n", sitenum);
            if(sitecnts[sitenum].first == 0) printf("NA\n");
            else printf("%d %d\n", sitecnts[sitenum].first, sitecnts[sitenum].second);
        }else{
            int date;
            scanf("%d", &date);
            printf("%06d\n", date);
            if(mp.count(date) == 0) printf("NA\n");
            else{
                vector<vnode> v;
                for(auto &x : mp[date]){
                    v.push_back(vnode(x.first, x.second));
                }
                sort(v.begin(), v.end(), cmp2);
                for(auto &x : v){
                    printf("%d %d\n", x.sitenum, x.cnts);
                }
            }
        }
    }
    return 0;
}
