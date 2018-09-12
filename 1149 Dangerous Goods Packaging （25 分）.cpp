#include <bits/stdc++.h>
using namespace std;
set<int> vst[100000];
bool DanGoodsSearch(int x, set<int> &st){
	for(int y: vst[x]){//x的不兼容物品y
		if(st.find(y) != st.end()) return false;//在该集装箱st中也含有y
	}
	return true;
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		int x, y;
		scanf("%d %d", &x, &y);
		vst[x].insert(y);
		vst[y].insert(x);
	}
	while(m--){
		int k, val, tag = 1;
		scanf("%d", &k);
		set<int> st;
		while(k--){
			scanf("%d", &val);
			st.insert(val);
		}
		for(int x: st){
			if(!DanGoodsSearch(x, st)){
				tag = 0; break;
			}
		}
		tag ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}
