#include <bits/stdc++.h>

using namespace std;

bool isprime(int n){
    if(n == 0 || n == 1) return false;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true;
}
int main()
{
    int n, m;
    string nums;
    cin >> n >> m >> nums;
    for(int i = 0; i <= n - m; ++i){
        string x = nums.substr(i, m);
        if(isprime(stoi(x))){
            cout << x << endl;
            return 0;
        }
    }
    cout << "404" << endl;
    return 0;
}
