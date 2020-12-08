#include<bits/stdc++.h>
using namespace std;
int arr[11];
// int fib(int num)
// {
//     if(arr[num]==-1)
//     {
//         if (num<=1)
//             arr[num] = num;
//         else
//         arr[num] = fib(num-1)+fib(num-2);
//     }
//     return arr[num];
// }

void fib(int num)
{
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2;i<num;i++)
    {
        arr[i] = arr[i-1]+arr[i-2];
    }
}

int main()
{
    for(int i=0;i<=10;i++)
    arr[i] = -1;
    fib(10);
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}