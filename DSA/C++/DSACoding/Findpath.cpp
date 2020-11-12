#include <iostream>
using namespace std;

static int res;

void findpath(int sr, int sc, int r, int c)
{
    if(sr==r && sc==c)
    {
        res+=1;
        return;
    }
    if(sr>r || sc>c)
    return;
    if(sr==r || sc==c)
    {
        res+=1;
        return;
    }
    findpath(sr+1,sc,r,c);
    findpath(sr,sc+1,r,c);
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        res = 0;
        cin>>r>>c;
        findpath(0,0,r-1,c-1);
        cout<<res<<endl;
    }
	return 0;
}