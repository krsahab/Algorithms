#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int k;
	    cin>>k;
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    sort(arr,arr+n);
	    int mi=arr[0]+k;
	    int ma = INT_MIN;
	    int height = INT_MAX;
	    for(int i=1;i<n;i++)
	    {
            int temp = abs((arr[i]+k)-mi);
            if(temp>abs((arr[i]-k)-mi))
            {
                mi = min(mi,arr[i]-k);
                ma = max(ma,arr[i]-k);
            }
            else
            {
                mi = min(mi,arr[i]+k);
	            ma = max(ma,arr[i]+k);
            }
	    }
	    cout<<abs(ma-mi)<<endl;
	}
	return 0;
}