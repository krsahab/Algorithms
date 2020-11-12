#include<bits/stdc++.h>
using namespace std;

int mindiff(vector<int> &A, vector<int> &B)
{
    int a=0,b=0;
    int m = INT_MAX;
    while(a<A.size() && b<B.size())
    {
        m = min(m,abs(A[a]-B[b]));
        if(A[a]>B[b])
        b++;
        else
        a++;
    }
    return m;
}
int solve(vector<int> &A) {
    vector<int> mi;
    vector<int> ma;
    int mn = A[0];
    mi.push_back(0);
    int mx = A[0];
    ma.push_back(0);
    for(int i=1;i<A.size();i++)
    {
        if(A[i]>mx)
        {
            ma.clear();
            ma.push_back(i);
        }
        if(A[i]==mx)
        ma.push_back(i);
        if(A[i]<mn)
        {
            mi.clear();
            mi.push_back(i);
        }
        if(A[i]==mn)
        mi.push_back(i);
    }
    return mindiff(mi,ma)+1;
}
int main()
{
    vector<int> v = {613, 116, 420, 672, 426};
    cout<<solve(v);
    return 0;
}