#include<bits/stdc++.h>
using namespace std;
int threeSumClosest(vector<int> &A, int B) {
    int s = A.size();
    long long int res = LONG_MAX;
    long long int sum=0;
    int opt;
    for(int i=0;i<s-2;i++)
    {
        for(int j=i+1;j<s-1;j++)
        {
            for(int k=j+1;k<s;k++)
            {
                sum=A[i]+A[j]+A[k];
                if(abs(sum-B)<res)
                {
                    res = abs(sum-B);
                    opt = sum;
                }
                
            }
        }
    }
    return opt;
}
int main()
{
    vector<int> v = {2147483647, -2147483648, -2147483648, 0, 1};
    cout<<threeSumClosest(v,-1);
    return 0;
}