#include<bits/stdc++.h>
//#define N = 50
using namespace std;

int MatSum(int arr[2][2], int n, int r, int c, int sr, int sc)
{
    int sum=0;
    for(int i=sr; i<=r;i++)
    {
        for(int j=sc; j<=c;j++)
        {
            sum+=arr[i][j];
        }
    }
    return sum;
}
bool is_rectangle(int arr[2][2], int n, int x, int r, int c)
{
    for(int i=r; i<n;i++)
    {
        for(int j=c; j<n;j++)
        {
            if(MatSum(arr,n,i,j,r,c)==x)
            return true;
        }
    }
    return false;
}

bool is_rectangle_there(int arr[2][2], int n, int x)
{
    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n;j++)
        {
            if(is_rectangle(arr,n,x,i,j))
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[2][2] = {{4,5},{9,10}};
    cout<<is_rectangle_there(arr,2,8);
    return 0;
}