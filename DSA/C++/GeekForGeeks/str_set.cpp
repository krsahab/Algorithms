#include<iostream>
#include<bits/stdc++.h>

using   namespace   std;

void    powerset(string str,int  index=0,string curr="")
{
    int n=str.length();
    if (index==n)
    {
        cout<<curr<<endl;
        return;
    }
    powerset(str,index+1,curr+str[index]);
    powerset(str,index+1,curr);
}
int main()
{
    powerset("ABC");
}