#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    //int *ptr = A.begin();
    int ptr=0;
    for(int i=0;i<B.size();i++)
    {
        while(A[ptr]<B[i] && ptr<A.size())
        ptr++;
        if(ptr<A.size())
        A.insert(A.begin()+ptr,B[i]);
        else
        A.push_back(B[i]);
    }
}

int main()
{
    vector<int> v1 = {1, 5, 8};
    vector<int> v2  = {6, 9};
    for(auto i:v1)
    cout<<i<<" ";
    merge(v1,v2);
    return 0;
}