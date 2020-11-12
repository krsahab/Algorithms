#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int arr[128] = {0};
	    int s;
	    cin>>s;
	    char c;
	    int mi = INT_MAX;
	    char result = '\0';
	    for(int i=0;i<s;i++)
	    {
	        cin>>c;
	        if(result=='\0')
	        {
	            if(arr[c]==0)
	            {
	                arr[c]=i+1;
	                result = c;
	            }
	            else if(arr[c]>0)
	            {
	                arr[c]=-2;
	            }
	        }
	        else if(result==c)
	            {
	                result = '\0';
                    arr[c]=-2;
	                mi = INT_MAX;
	                for(int j=0;j<128;j++)
	                {
	                    if(arr[j]>0)
	                    {
	                        if(arr[j]<mi)
	                        {
	                            mi = arr[j];
	                            result = j;
	                        }
	                    }
	                }
	            }
	            if(result=='\0')
	            cout<<"-1"<<" ";
	            else
	            cout<<result<<" ";
	    }
	}
	return 0;
}