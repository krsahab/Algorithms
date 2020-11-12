#include <iostream>
using namespace std;

int optimal(int arr[], int s, int e)
{
    if(s==e)
    return arr[s];
    if(s+1==e)
    return max(arr[s],arr[e]);
    return max(arr[s]+min(optimal(arr,s+2,e),optimal(arr,s+1,e-1)),
    arr[e]+min(optimal(arr,s+1,e-1),optimal(arr,s,e-2)));
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int l;
        cin>>l;
        int arr[l];
        for(int i=0;i<l;i++)
        cin>>arr[i];
        cout<<optimal(arr,0,l-1)<<endl;
    }
	return 0;
}