#include<bits/stdc++.h>
using namespace std;

int mostBalancedPartition(vector<int> parent, vector<int> files_size) {
    int s = parent.size();
    int sum[s] = {0};
    int totalsum = files_size[0];
    sum[0] = files_size[0];
    for(int i=1;i<s;i++)
    {
        sum[parent[i]]+=files_size[i];
        sum[i]+=files_size[i];
        totalsum+=files_size[i];
    }
    int diff = 0;
    int res = INT_MAX;
    for(int i=0;i<s;i++)
    {
        diff = totalsum-sum[i];
        res = min(res,diff);
    }
    return res;
}

int main()
{
    vector<int> v1 = {-1,0};
    vector<int> v2 = {20,100};
    cout<<mostBalancedPartition(v1,v2);
    return 0;
}