#include<bits/stdc++.h>
using namespace std;

int catchThieves(char arr[], int n, int k) 
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]=='P')
        {
            int j = i-k>0?i-k:0;
            int l = i+k<n?i+k:n-1;
            for(int t=j;t<=l;t++)
            {
                if(arr[t]=='T')
                {
                count++;
                arr[t]=='N';
                break;
                }
            }
        }
    }
    return count;
}

int main()
{
    char arr[] = {'T', 'T', 'P', 'P', 'T', 'P'};
    cout<<catchThieves(arr,6,2);
    return 0;
}