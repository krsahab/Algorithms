#include<bits/stdc++.h>
using namespace std;

int findK(int A[3][3], int n, int m, int k)
{
    int rs=0,cs=0,re=n-1,ce=m-1;
    int r=0,c=0;
    while(rs!=re && cs!=ce)
    {
        for(c=cs;c<=ce;c++)
        {
            k--;
            if(k==0)
            return A[r][c];
        }
        rs=rs+1;
        c=c-1;
        for(r=r+1;r<=re;r++)
        {
            k--;
            if(k==0)
            return A[r][c];
        }
        r=r-1;
        ce = ce-1;
        for(c=c-1;c>=cs;c--)
        {
            k--;
            if(k==0)
            return A[r][c];
        }
        c=c+1;
        re=re-1;
        for(r=r-1;r>=rs;r--)
        {
            k--;
            if(k==0)
            return A[r][c];
        }
        r=r+1;
        cs=cs-1;
    }
    return A[rs][cs];
}

int main()
{
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int result=findK(arr,3,3,4);
    cout<<result;
    return 0;
}