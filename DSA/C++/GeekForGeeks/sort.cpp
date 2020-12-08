#include<iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *y;
    *y=*x;
    *x=temp;
}

void selectionsort(int arr [], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j]<arr[min_idx])
            min_idx = j;
            if(arr[i]>arr[min_idx])
            swap(&arr[i],&arr[min_idx]);
        }
        
    }
    
}

void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
}



void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

void insertionsort(int arr[], int n)
{
    for(int i = 1; i<n;i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge(int arr[], int start, int middle, int end)
{
    int left_length = middle-start+1;
    int right_length = end - middle;
    int left[left_length];
    int right[right_length];
    for (int i = 0; i < left_length; i++)
        left[i] = arr[start+i];
    for (int j = 0; j < right_length; j++)
        right[j] = arr[middle+j+1];
    int k = start, i=0, j=0;
    while(i<left_length && j<right_length)
    {
        if(left[i]<=right[j])
        arr[k] = left[i++];
        else
        arr[k] = right[j++];
        k++;
    }
    while(i<left_length)
    arr[k++] = left[i++];
    while(j<right_length)
    arr[k++] = right[j++];
}

void mergesort(int arr[], int left, int right)
{
    if(left<right)
    {
        int m = left+(right-left)/2;
        mergesort(arr,left,m);
        mergesort(arr,m+1,right);
        merge(arr,left,m,right);
    }
}

int partition(int arr[], int s, int e)
{
    int pivot = arr[e];
    int i = s-1;
    for(int j=s; j<e; j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(&arr[i+1],&arr[e]);
    return i+1;
}

void quicksort(int arr[], int s, int e)
{
    if(s<e)
    {
        int m = partition(arr,s,e);
        quicksort(arr,s,m-1);
        quicksort(arr,m+1,e);
    }
}

int main()
{
    int arr[] = {0,7,7,2,2,17,44,22,83,100005,66};
    int size = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,size-1);
    printarray(arr,size);
}