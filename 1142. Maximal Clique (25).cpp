#include <bits/stdc++.h>
using namespace std;
vector<int> v[256];
int A[256][256];
void judge(vector<int> &seq)
{
	int n=seq.size(),visit[256]={};
	for(int i=0;i<n;++i){
		visit[seq[i]]=1;
		for(int j=i+1;j<n;++j){
			if(A[seq[i]][seq[j]]==0){
				printf("Not a Clique\n");
				return;
			}
		}
	}
	for(int z:seq){
		for(int x:v[z]){
			if(visit[x]==0){//对seq里z的一个没有访问过的邻接点x
				int tag=1;
				for(int y:seq){
					if(A[x][y]==0){
						tag=0;//该点和seq的其他不相邻
						break;
					}
				}
				if(tag==1){//不存在不相邻的点，存在另一点使得他们相邻，因此是not maximal的
					printf("Not Maximal\n");
					return;
				}
			}
		}
	}
	printf("Yes\n");
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
		A[x][y]=A[y][x]=1;
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int k,val;
		scanf("%d",&k);
		vector<int> seq;
		while(k--){
			scanf("%d",&val);
			seq.push_back(val);
		}
		judge(seq);
	}
	return 0;
}
