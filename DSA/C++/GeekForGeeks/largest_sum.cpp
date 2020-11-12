#include<bits/stdc++.h>
#include<hash_map>

using namespace std;

int maxLen(int A[],int n)
{
    unordered_map<int,int> us;
    int sum = 0;
    int max_len = 0;
    for(int i=0; i<n; i++)
    {
        sum+=A[i];
        if(A[i]==0&&max_len==0)
        max_len=1;
        if(sum=0)
        max_len=i+1;
        if(us.find(sum)!=us.end())
        {
            int len = i-us[sum];
            if(len>max_len)
            max_len = len;
        }
        else
        us[sum]=i;
    }
    return max_len;
}

int main() 
{ 
    int arr[] = { 15, -2, 2, -8, 1, 7, 10, 23 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Length of the longest 0 sum subarray is "
         << maxLen(arr, n); 
  
    return 0; 
} 