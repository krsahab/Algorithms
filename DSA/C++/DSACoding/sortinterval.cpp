#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> p1,pair<int,int> p2)
{
    return p1.first<p2.first;
}

int max_non_overlapping( vector< pair<int,int> >& ranges )
{
    sort(ranges.begin(),ranges.end(),cmp);
    int count=0;
    for(int i=0;i<ranges.size()-1;i++)
    {
        if(ranges[i].second<=ranges[i+1].first)
        count++;
    }
    return count;
}

int main()
{
    
    cout<<max_non_overlapping()<<endl;
    return 0;
}