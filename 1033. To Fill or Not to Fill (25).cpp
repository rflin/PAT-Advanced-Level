/*考察贪心
思路：
当car到达某个加油站点后，那么，下一次car最远可以跑的范围一定是cmax*davg，我们的贪心策略便依据于此
依次遍历从当前站点到cmax*davg范围内的所有加油站，则：
1、一旦发现一个比当前站点花费更小的站点，ok，在当前站点加油至刚好到达此站，然后驶向此站
2、该范围内没有比当前站点花费更少的站点，ok，在当前站点加满油，到达下一个花费最小的站点
*/
#include <bits/stdc++.h>
using namespace std;
struct station
{
    double price;
    double distance;
};
bool comp(const station &a,const station &b)
{
    return a.distance<b.distance;
}
int main()
{
    double cmax,d,davg,n;
    vector<station> v;
    cin>>cmax>>d>>davg>>n;
    while(n--)
    {
        station temp;
        cin>>temp.price>>temp.distance;
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),comp);
    double consum=0.0,curgas=0.0,curd=0.0;
    bool iscompelete=true;
    if(v[0].distance!=0)//初始点无加油站，跑不动啊啊啊啊啊啊:(
    {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    for(auto it=v.begin();it!=v.end();)
    {
        auto p=it,next=it,less=it+1;
        //p:进行循环迭代；  next：第一个比当前站点花费更少的站点；
        //less：好吧，next不存在，就用less你记录当前范围内花费最少的站点吧（此时，其他站点都比当前站点价格高）
        double distances=0.0,addgas=0.0;
        while(p!=v.end()&&p->distance-it->distance<=cmax*davg)
        {
            if(p->price<it->price)//找到一个比当前加油站价格小就立即break
            {
                next=p;//找到了:)，记录下一站点
                break;
            }
            if(p!=it)
                less=(p->price<less->price)?p:less;
            ++p;
        }
        if(p==v.end())
        {
            if(d-it->distance>cmax*davg)//加完最后一个站点不能够到达终点
            {
                iscompelete=false;//未完成
                curd+=cmax*davg;
                break;
            }
            //能到终点
            distances=d-it->distance;//到终点还剩下的路程
            consum+=(distances/davg-curgas)*it->price;//累计消费
            break;
        }
        if(next!=it)//找到一个比当前站点花费更少的站点
        {
            distances=next->distance-it->distance;//到下一个站点的距离
            addgas=distances/davg-curgas;//新加的油
            consum+=it->price*addgas;//累计消费
            curd=next->distance;//记录距离
            curgas=0.0;//加的油只够跑到下一个站点，当然跑到下一站点油箱剩余0
            it=next;
        }
        else//在此段距离没能找到一个比当前站点花费更少的站点（都比当前站点花费更多）
        {//好吧，先在这个站点先给它加满油再说，找到下一个花费最少的站点
            distances=less->distance-it->distance;//less是之前记录的花费最少的站点
            addgas=cmax-curgas;//加满需要新加的油
            consum+=it->price*addgas;//累计消费
            curd=less->distance;//记录距离
            curgas=cmax-distances/davg;//跑到下一站点时油箱剩余油量
            it=less;
        }
    }
    if(iscompelete) printf("%.2lf",consum);//完成路径:)
    else printf("The maximum travel distance = %.2lf",curd);//oh,No!未完成:(
    return 0;
}
