#include <bits/stdc++.h>
using namespace std;

struct interval{
  int index, start, end;
  interval(int a, int b, int c)
  {
      index = a;
      start = b;
      end = c;
  }
  
};

bool compareInterval(interval *i1, interval *i2)
{
    return i1->end<i2->end;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int s;
        cin>>s;
        int *st = new int[s];
        int *et = new int[s];
        for(int i=0;i<s;i++)
        cin>>st[i];
        for(int i=0;i<s;i++)
        cin>>et[i];
        vector<interval*> v;
        for(int i=0;i<s;i++)
        {
            interval *inte = new interval(i,st[i],et[i]);
            v.push_back(inte);
        }
        sort(v.begin(), v.end(), compareInterval);
        int curr = v.front()->end;
        cout<<v.front()->index+1<<" ";
        v.erase(v.begin());
        while(!v.empty())
        {
            if(v.front()->start>curr)
            {
            cout<<v.front()->index+1<<" ";
            curr = v.front()->end;
            }
            v.erase(v.begin());
        }
        cout<<endl;
    }
	return 0;
}