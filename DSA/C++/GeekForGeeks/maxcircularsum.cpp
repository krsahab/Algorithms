#include<bits/stdc++.h>
using namespace std;

int circularSubarraySum(int arr[], int num){
    
    int s = 0,e = num-1;
    int maxSum = arr[e];
    int sum = arr[e];
    e--;
    bool flag = true;
    int i;
    while(s<e)
    {
        flag=!flag;
        if(flag)
        {
            i=e;
            e--;
        }
        else
        {
            i=s;
            s++;
        }
        if(sum<0)
        {
            sum=max(sum,arr[i]);
            maxSum = max(maxSum,arr[i]);
        }
        else
        {
            if(sum+arr[i]>0)
            {
                sum = sum+arr[i];
                maxSum = max(sum,maxSum);
            }
        }
    }
    return maxSum;
}

int main()
{
    int arr[] = {8, -8, 9, -9, 10, -11, 12};
    cout<<circularSubarraySum(arr,7);
    return 0;
}