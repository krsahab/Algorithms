#include<bits/stdc++.h>
using namespace std;


//maybe not right
bool issafe(string str, int l, int r, int i)
{
    if(l!=0 && str[l-1]=='A' && str[i]=='B')
    return false;
    if(r=l+1 && str[l]=='A' && str[i]=='B')
    return false;
    return true;
}

void permute(string str, int l, int r)
{
    if(l==r)
    cout<<str<<" ";
    else
    {
        for (int i = l; i <= r; i++)
        {
            if (issafe(str,l,r,i))
            {
                swap(str[l],str[i]);
                permute(str,l+1,r);
                swap(str[l],str[i]);
            }
        }
    }
}

int main()
{
    string str = "ABC";
    permute(str,0,2);
    return 0;
}