#include<bits/stdc++.h>
using namespace std;
//no. of 1's till a number n
int solve(int A) {
    int b= A,n;
    int sum=0;
    for(int i=1; i<=A; i*=10)
    {
        n = b%10;
        b = b/10;
        if(n==1)
        {
            sum = sum+((A%i)+1);
            sum = sum+(b)*i;
        }
        else if(n==0)
        {
            sum = sum+b*i;
        }
        else
        {
            sum = sum+(b+1)*i;
        }
    }
    return sum;
}
int main()
{
    cout<<solve(13);
    return 0;
}