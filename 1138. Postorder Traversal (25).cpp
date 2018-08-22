#include <iostream>
using namespace std;
int pre[50000], ino[50000], res;
void getFirstInPos(int preL, int preR, int inoL, int inoR){
	if(preL > preR) return;
	int e = pre[preL], idx = inoL;
	while(e != ino[idx]) ++idx;
	res = e;
	if(idx == inoL) getFirstInPos(preL + 1, preR, inoL + 1, inoR);
	else getFirstInPos(preL + 1, idx - 1 - inoL + preL + 1, inoL, idx - 1);
}
int main()
{
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> pre[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> ino[i];
	}
	getFirstInPos(0, n-1, 0, n-1);
	cout << res << endl;
	return 0;
}
