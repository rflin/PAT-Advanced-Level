/*此处采用的方法是自己尝试写的分治算法（nlogn）
实际上，该题算法复杂的o(n^2)也能过（嵌套两次循环），略
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int v[10004],n;
bool check=0;
struct LRS
{
    int left,right,sum;
    LRS(int l,int r,int s):left(l),right(r),sum(s){}
    bool operator<(const LRS &a)const
    {
        return sum==a.sum?left>a.left:sum<a.sum;
    }
};
LRS CrossSubseq(int A[],int low,int high,int mid)
{
    int lmax=0x80000000,rmax=0x80000000;
    int sum=0,l,r;
    for(int i=mid;i>=low;--i)
    {
        sum+=A[i];
        if(lmax<sum)
        {
            lmax=sum;
            l=i;
        }
    }
    sum=0;
    for(int i=mid+1;i<=high;++i)
    {
        sum+=A[i];
        if(rmax<sum)
        {
            rmax=sum;
            r=i;
        }
    }
    return LRS(l,r,lmax+rmax);
}
LRS MaxSubseq(int A[],int low,int high)
{
    if(low==high) return LRS(low,high,A[low]);
    return max(max(MaxSubseq(A,low,(low+high)/2),MaxSubseq(A,(low+high)/2+1,high)),CrossSubseq(A,low,high,(low+high)/2));
}
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
        if(v[i]>=0) check=1;
    }
    LRS o=(check)?MaxSubseq(v,0,n-1):LRS(0,n-1,0);
    cout<<o.sum<<" "<<v[o.left]<<" "<<v[o.right];
    return 0;
}
