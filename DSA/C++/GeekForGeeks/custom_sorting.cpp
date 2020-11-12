#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> um;

int custom_sort(const void* a, const void* b)
{
    int n1 = *(int*)a;
    int n2 = *(int*)b;
    if(n1==n2)
    return 0;
    if(um.find(n1)!=um.end())
    {
        if(um.find(n2)!=um.end())
        {
            return um[n1]-um[n2];
        }
        return -1;
    }
    else if(um.find(n2)!=um.end())
    {
        return 1;
    }
    else
    {
        return n1-n2;
    }
}

void sortA1ByA2(int A1[], int N, int A2[], int M) 
{
    um.clear();
    for(int i=0;i<M;i++)
    {
        um.insert({A2[i],i});
    }
    //sort(A1,A1+N,custom_sort);
    qsort(A1, N, sizeof(int), custom_sort); 
} 

int main()
{
    int A1[]={2,1,2,5,7,1,9,3,6,8,8};
    int A2[]={99,22,444,56};
    sortA1ByA2(A1,11,A2,4);
    for (int i = 0; i < 11; i++)
    {
        cout<<A1[i]<<" ";
    }
    
    return 0;
}