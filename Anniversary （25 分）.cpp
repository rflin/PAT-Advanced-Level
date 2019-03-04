#include <bits/stdc++.h>

using namespace std;
string oldbirth = "99999999", oldid;
string guestbirth = "99999999", guestid;
map<string, int> mp;
int main()
{
    int n;
    cin >> n;
    cin.get();
    for(int i = 0; i < n; ++i){
        string id;
        cin >> id;
        mp[id] = 1;
    }
    int m, cnt = 0;
    cin >> m;
    cin.get();
    for(int i = 0; i < m; ++i){
        string id;
        cin >> id;
        string y = id.substr(6, 8);
        if(mp.count(id) == 1) {//与会人员有校友
            ++cnt;
            if(y < oldbirth){
                oldbirth = y;
                oldid = id;
            }
        }
        if(y < guestbirth){
            guestbirth = y;
            guestid = id;
        }
    }
    cout << cnt << endl;
    if(cnt > 0) cout << oldid << endl;
    else cout << guestid << endl;
    return 0;
}
