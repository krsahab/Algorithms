#include<bits/stdc++.h>

using namespace std;

void permute(string s, int fac, int st)
{
    if(fac==1)
    {
        cout<<s<<endl;
        return;
    }
    int per = ((s.size()-st)/fac);
    per += (s.size()-st)%fac;
    for (int i = 0; i < per; i++)
    {
        s.insert(st+i+1, ".");
        permute(s, fac-1, st+i+2);
        s.erase(st+i+1, 1);
    }
       
}

void printip(string s)
{
    permute(s, 4, 0);
}

int main()
{
    string s = "1987456978964569";
    printip(s);
    return 0;
}