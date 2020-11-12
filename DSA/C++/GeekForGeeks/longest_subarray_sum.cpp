#include<bits/stdc++.h>

using namespace std;

int longestSum(int arr[], int size, int k)
{
    unordered_map <int,int> um;
    int sum = 0,max_len=0;
    for(int i=0;i<size;i++)
    {
        sum=sum+arr[i];
        if(sum==k)
            max_len = i+1;

        if(um.find(sum)==um.end())
        {
            um[sum] = i;
        }
        if(um.find(sum-k)!=um.end())
        {
            if(max_len<i-um[sum-k])
            max_len = i-um[sum-k];
        }
    }
    return max_len;
}

int main()
{
    int arr[] = {10, 5, 2, 7, 1, 9};
    int k = 15;
    int size = sizeof(arr)/sizeof(arr[0]);
    int longest_sum = longestSum(arr,size,k);
    cout<<longest_sum;
}