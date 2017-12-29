#include <iostream>
#include <queue>
using namespace std;
const int Maxi=128,Maxj=1286,Maxk=60;
int Matrix[Maxi][Maxj][Maxk];
int n,m,l,t,ans=0;
int dx[6]={1,0,0,-1,0,0};
int dy[6]={0,1,0,0,-1,0};
int dz[6]={0,0,1,0,0,-1};
struct node
{
    int x,y,z;
};
bool israng(int x,int y,int z)
{
    if(x>=0&&x<n&&y>=0&&y<m&&z>=0&&z<l)
        return true;
    return false;
}
void bfs(int x,int y,int z)
{
    int ret=0;
    node temp;
    temp.x=x;temp.y=y;temp.z=z;
    queue<node> q;
    q.push(temp);Matrix[x][y][z]=0;++ret;
    while(!q.empty())
    {
        node cur=q.front();
        q.pop();
        for(int i=0;i<6;++i)
        {
            int nx=cur.x+dx[i];
            int ny=cur.y+dy[i];
            int nz=cur.z+dz[i];
            if(israng(nx,ny,nz)&&Matrix[nx][ny][nz])
            {
                Matrix[nx][ny][nz]=0;++ret;
                temp.x=nx;temp.y=ny;temp.z=nz;
                q.push(temp);
            }
        }
    }
    if(ret>=t)
        ans+=ret;
}
int main()
{
    cin>>m>>n>>l>>t;
    for(int k=0;k<l;++k)
        for(int j=0;j<m;++j)
            for(int i=0;i<n;++i)
                cin>>Matrix[i][j][k];
    for(int k=0;k<l;++k)
        for(int j=0;j<m;++j)
            for(int i=0;i<n;++i)
                if(Matrix[i][j][k])bfs(i,j,k);
    cout<<ans;
    return 0;
}
