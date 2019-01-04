#include <bits/stdc++.h>
using na
mespace std;
vector<int> v, vx;
int n, res;
void MaxHeap(int i){
    if(i <= n){
        if((2 * i + 1 <= n && v[2 * i + 1] > v[i]) || (2 * i <= n && v[2 * i] > v[i])) res = 0;
        if((2 * i > n)) vx.push_back(i);
        MaxHeap(2 * i + 1);
        MaxHeap(2 * i);
    }
}
void MinHeap(int i){
    if(i <= n){
        if((2 * i + 1 <= n && v[2 * i + 1] < v[i]) || (2 * i <= n && v[2 * i] < v[i])) res = 0;
        if((2 * i > n)) vx.push_back(i);
        MinHeap(2 * i + 1);
        MinHeap(2 * i);
    }
}
void prt(vector<int> &vx){
    for(int i: vx){
        stack<int> stk;
        while(i >= 1){
            stk.push(v[i]);
            i /= 2;
        }
        while(!stk.empty()){
            stk.size() == 1 ? printf("%d\n", stk.top()) : printf("%d ", stk.top());
            stk.pop();
        }
    }
}
int main()
{
    cin >> n;
    v.resize(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
    }
    res = 1;
    if(v[1] > v[2]){
        MaxHeap(1);
        prt(vx);
        res ? printf("Max Heap\n") : printf("Not Heap\n");
    }else{
        MinHeap(1);
        prt(vx);
        res ? printf("Min Heap\n") : printf("Not Heap\n");
    }
    return 0;
}
