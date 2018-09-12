#include <bits/stdc++.h>
using namespace std;
int A[128];
bool help(int i, int j, int lier, int n){
	for(int k = 1; k <= n; ++k){
		if(k == i || k == j) continue;
		A[lier] = -A[lier]; A[k] = -A[k];//说谎玩家取反
		vector<int> v(n + 1);//v中的取值为0（未进行推理），1（人类），-1（狼）
		v[i] = v[j] = -1;//i, j为两只狼
		bool tag = 1;
		for(int l = 1; l <= n; ++l){
			int w = abs(A[l]), val = A[l] / w;
			if(v[w] * val < 0){//与事实矛盾
				tag = 0;
				break;
			}
			v[w] = val;
		}
		int count = 0;
		for(int l = 1; l <= n; ++l) if(v[l] == -1) ++count;//有且只有两只狼
		if(tag && count == 2) return true;
		A[lier] = -A[lier]; A[k] = -A[k];
	}
	return false;
}
void WerewolfSol(int n){
	for(int i = 1; i <= n - 1; ++i){
		for(int j = i + 1; j <= n; ++j){
			if(help(i, j, i, n) || help(i, j, j, n)){
				printf("%d %d\n", i, j);
				return;
			}
		}
	}
	printf("No Solution\n");
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", A + i);
	}
	WerewolfSol(n);
	return 0;
}
