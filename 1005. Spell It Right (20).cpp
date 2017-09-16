#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> v={"zero","one","two","three","four","five","six","seven","eight","nine"};
int sum=0;
int main()
{
	char c;
	while((c=cin.get())!='\n') sum+=c-'0';
	string str=to_string(sum);
	for(unsigned int i=0;i<str.size();++i)
	{
		i==str.size()-1?cout<<v[str[i]-'0']:cout<<v[str[i]-'0']<<" ";
	}
	return 0;
}
