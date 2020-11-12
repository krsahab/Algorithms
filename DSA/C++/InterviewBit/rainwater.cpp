#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int trap(int *A, int n) {
    int post[n];
    post[n-1] = A[n-1];
    for(int i=n-2;i>0;i--)
    {
        post[i] = max(A[i],post[i+1]);
    }
    int lm = A[0], sum=0;
    for(int i=1;i<n-1;i++)
    {
        lm = max(lm,A[i]);
        sum= sum+min(lm,post[i])-A[i];
    }
    return sum;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int s;
        cin>>s;
        int arr[s];
        for(int i=0;i<s;i++)
        {
            cin>>arr[i];
}
        cout<<trap(arr,s)<<endl;
}
    
    return 0;
}
