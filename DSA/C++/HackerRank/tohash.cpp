#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "000A";
    int len = s.size();
    unsigned long long num1 = 0;
    unsigned long long num2 = 0;
    for(int i=0;i<len;i++)
    {
        num1+=s[i]*pow(131, len-i);
        num2+=s[i]*pow(131, len);
    }
    num1 = num1%(1000000007);
    num2 = num2%(1000000007);
    cout<<num1<<endl;
    cout<<num2<<endl;
    return 0;
}