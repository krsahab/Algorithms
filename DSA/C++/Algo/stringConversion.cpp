#include<bits/stdc++.h>
using namespace std;

// int minDist(string s1, string s2, int n1, int n2)
// {
//     if(n1==0)
//     return n2;
//     if(n2==0)
//     return n1;
//     if(s1[n1-1]==s2[n2-1])
//     return minDist(s1, s2, n1-1, n2-1);
//     else
//     return 1+min(minDist(s1,s2,n1-1,n2), min(minDist(s1,s2,n1,n2-1), minDist(s1,s2,n1-1,n2-1)));
// }

int main()
{
    string s1 = "CUT";
    string s2 = "CAT";
    cout<<minDist(s1,s2,3,3);
    return 0;
}