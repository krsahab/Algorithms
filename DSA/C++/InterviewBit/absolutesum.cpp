#include<bits/stdc++.h>
using namespace std;
//max absolute sum of multiple arrays
void toBinary(int n, int *arr)
{
    std::string r;
    int i=4;
    while(n!=0) {n%2==0 ?arr[i]=-1:arr[i]=1; i--; n/=2;}
}

int solve(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
    int mis = INT_MAX, mas = INT_MIN, mid = INT_MAX, mad = INT_MIN;
    int sum = 0;
    int res = INT_MIN;
    int arr[5] = {-1,-1,-1,-1,-1};
    for(int i=0;i<=31;i++)
    {
        toBinary(i, arr);
        mis = INT_MAX, mas = INT_MIN;
        for(int j=0; j<A.size(); j++)
        {
            sum = arr[0]*A[j] + arr[1]*B[j] + arr[2]*C[j] + arr[3]*D[j] + arr[4]*j;
            mis = min(mis,sum);
            mas = max(mas,sum);
        }
        res = max(res,abs(mas-mis));
    }
    return res;
}

int main()
{
   vector<int> A  =  { -27, -7, -48 };
    vector<int> B = { -40, -33, -43 };
    vector<int> C = { -22, -22, -16 };
    vector<int> D = { -22, -5, -2 };
    cout<<solve(A,B,C,D);
    return 0;
}