#include<bits/stdc++.h>
using namespace std;

int findrank(string str)
{
    string s2 = str;
    sort(s2.begin(),s2.end());
    int rank=1;
    do
    {
        if(str==s2)
        break;
        rank++;
    } while (next_permutation(s2.begin(),s2.end()));
    return rank;
}

int main()
{
    string str = "acb";
    cout<<findrank(str);
    return 0;
}