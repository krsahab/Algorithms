#include <iostream>
using namespace std;

int CountAndMerge(int a[],int l,int m,int r)
{
    int res = 0;
    int sizeLeft = m-l+1;
    int sizeRight = r-m;
    int left[sizeLeft];
    int right[sizeRight];
    for(int i = 0;i<sizeLeft; i++)
    {
       left[i] = a[l+i] ;
    }
    for(int i = 0;i<sizeRight; i++)
    {
       right[i] = a[m+1+i] ;
    }
    int i =0,j=0,k=l;
    while(i < sizeLeft && j < sizeRight)
    {
        if(left[i]<=right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
            res+=sizeLeft-i;
        }
        k++;
    }
    while(i < sizeLeft)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while(j < sizeRight)
    {
        a[k] = right[j];
        j++;
        k++;
    }
    return res;
}
int CountInv(int a[],int l, int r)
{
    int res = 0;
    int m = l +((r-l)/2);
    if(l<r)
    { 
        res += CountInv(a,l,m);
        res += CountInv(a,m+1,r);
        res += CountAndMerge(a,l,m,r);
    }
    return res;
}

int main() {
   
    int T;
    cin >> T;
   
    while(T--){
        int N;
        cin >> N;
       
        int *A = new int[N];
        for(int i = 0;i<N;i++){
            cin >> A[i];
        }
       
        cout << CountInv(A,0,N-1) << endl;
    }
   
    return 0;
}