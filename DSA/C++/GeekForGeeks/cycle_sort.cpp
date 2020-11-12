#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void swap(int *n1, int* n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void Cycle_sort(int* arr, int len)
{
    for (int i = 0; i < len-1; i++)
    {
        loop:
        int pos = i;
        int no = arr[i];
        for (int j = i+1; j < len; j++)
        {
            if (arr[j]<no)
                pos++;
        }
        if(pos==i)
        continue;
        while (no==arr[pos])
            pos++;        
        if(pos!=i)
        {
            swap(&arr[i],&arr[pos]);
            goto loop;
        }
    }
}

int main()
{
    int arr[] = {7, 2, 1, 3, 0, 7, -1, 7, 4};

int len = sizeof(arr)/sizeof(arr[0]);
Cycle_sort(arr,len);
for (int i = 0; i < len; i++)
{
    cout<<arr[i]<<" ";
}
return 0;
}