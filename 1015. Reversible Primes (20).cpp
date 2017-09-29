#include <bits/stdc++.h>
using namespace std;
bool isprime(int n){
	if(n<2)
		return false;
	for(int i=2;i*i<=n;++i){
		if(n%i==0)
			return false;
	}
	return true;
}
int convert(int num,int radix){
	int m=0;
	while(num){
		m=m*radix+num%radix;
		num/=radix;
	}
	return m;
}
int main(){
	int n,radix;
	while(cin>>n&&n>=0){
		cin>>radix;
		if(isprime(n)&&isprime(convert(n,radix)))
			puts("Yes");
		else puts("No");
	}
}
