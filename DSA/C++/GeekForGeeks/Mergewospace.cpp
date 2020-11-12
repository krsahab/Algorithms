#include<bits/stdc++.h>

using namespace std;

/*void swap(long *n1,long *n2)
{
    long  temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}*/

void merge(long *arr1, long *arr2, long l1, long l2)
{
    priority_queue<int,vector<int>,greater<int>> pq(arr2,arr2+l2);
    for (long  i=0; i<l1; i++)
    {
        if(arr1[i]>pq.top())
        {
            int t = pq.top();
            pq.pop();
            pq.push(arr1[i]);
            arr1[i]=t;
        }
    }
    int i=0;
    while(!pq.empty())
    {
        arr2[i++]=pq.top();
        pq.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned int t;
    cin>>t;
    while(t--)
    {
        long l1,l2,i,j;
        cin>>l1;
        cin>>l2;
        long arr1[l1];
        long arr2[l2];
        for(i=0;i<l1;i++)
        cin>>arr1[i];
        for(j=0;j<l2;j++)
        cin>>arr2[j];
        merge(arr1,arr2,l1,l2);
        for(i=0;i<l1;i++)
        cout<<arr1[i]<<" ";
        for(j=0;j<l2;j++)
        cout<<arr2[j]<<" ";
        cout<<endl;
    }
    return 0;
}