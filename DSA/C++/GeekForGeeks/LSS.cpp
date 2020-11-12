#include <iostream>
using namespace std;

int LSS(int arr[], int s)
{
    int res=arr[0];
    int sum[s] = {0};
    sum[0] = arr[0];
    for(int i=1;i<s;i++)
    {
        sum[i]=arr[i];
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            {
                sum[i] = max(sum[i],sum[j]+arr[i]);
            }
        }
        res = max(res,sum[i]);
    }
    return res;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int s;
	    cin>>s;
	    int arr[s];
	    for(int i=0;i<s;i++)
	        cin>>arr[i];
	    cout<<LSS(arr,s)<<endl;
	}
	return 0;
}