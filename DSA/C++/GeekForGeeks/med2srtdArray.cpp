#include<bits/stdc++.h>

using namespace std;

int secondIndex(int n1, int n2, int i)
{
    return (n1+n2+1)/2 - i;
}

int findMedian(int arr1[], int n1, int arr2[], int n2)
{
    int begin = 0, end = n1;
    while (begin<=end)
    {
        int med1 = (begin+end)/2;
        int med2 = secondIndex(n1, n2, med1);
        int min1 = (med1==n1)?INT_MAX:arr1[med1];
        int min2 = (med2==n2)?INT_MAX:arr2[med2];
        int max1 = (med1>=0)?arr1[med1]:INT_MIN;
        int max2 = (med2>=0)?arr2[med2]:INT_MIN;
        if(max1>min2)
            end = med1-1;
        else if(max2>min1)
            begin = med1+1;
        else
        {
            if((n1+n2)%2 == 0)
                return double(max(max1, max2)+min(min1, min2)/2);
            else
                return double(max(max1, max2));
        }
    }
}

int main()
{
    int arr1[] = {10, 20, 30, 40, 50};
    int arr2[] = {5, 15, 20, 25, 30, 35, 40, 45, 50, 55, 65, 75, 80, 85};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    cout<<findMedian(arr1, n1, arr2, n2)<<endl;
    return 0;
}