#include <bits/stdc++.h>

using namespace std;

bool isprime(int n){
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true;
}
int sol(int n){
    if(isprime(n) && isprime(n - 6)) return n - 6;
    else if(isprime(n) && isprime(n + 6)) return n + 6;
    return 0;
}
int main()
{
    int n, res = 0;
    scanf("%d", &n);
    res = sol(n);
    if(res > 0){
        printf("Yes\n%d", res);
    }else{
        ++n;
        while((res = sol(n)) == 0) ++n;
        printf("No\n%d", n);
    }
    return 0;
}
