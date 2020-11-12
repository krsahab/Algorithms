#include <bits/stdc++.h>
using namespace std;

int sum;
int res;
void minDiff(int arr[], int n, int s)
{
    if(n<0)
    return;
    res = min(res,abs(sum-s));
    minDiff(arr,n-1,s+arr[n]);
    minDiff(arr,n-1,s);
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int l;
	    cin>>l;
	    int arr[l];
	    sum=0;
	    for(int i=0;i<l;i++)
	    {
	        cin>>arr[i];
	        sum+=arr[i];
	    }
	    res=sum;
	    minDiff(arr,l-1,0);
	    cout<<res<<endl;
	}
	return 0;
}