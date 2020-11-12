#include <iostream>
using namespace std;

int maxcuts(int len, int x, int y, int z)
{
    if(len==0)
    return 0;
    int res=0;
    if(len>=x)
    res=1+maxcuts(len-x,x,y,z);
    if(len>=y)
    res=max(res,1+maxcuts(len-y,x,y,z));
    if(len>=z)
    res=max(res,1+maxcuts(len-z,x,y,z));
    return res;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int len;
        cin>>len;
        int x,y,z;
        cin>>x>>y>>z;
        cout<<maxcuts(len,x,y,z)<<endl;
    }
	return 0;
}