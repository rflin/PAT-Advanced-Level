#include <bits/stdc++.h>
using namespace std;
bool isprime(int k){
    if(k == 0) return false;
    for(int i = 2; i * i <= k; ++i){
        if(k % i == 0) return false;
    }
    return true;
}
int main()
{
    string nums;
    int L, n;
    cin >> L >> n >> nums;
    for(int i = 0; i <= L - n; ++i){
        string x = nums.substr(i, n);
        if(isprime(stol(x))){
            cout << x << endl;
            return 0;
        }
    }
    cout << "404" <<endl;
    return 0;
}
