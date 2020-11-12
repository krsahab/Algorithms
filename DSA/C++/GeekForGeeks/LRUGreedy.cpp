#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int len;
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++)
        cin>>arr[i];
        int cap;
        cin>>cap;
        int res = min(cap,len);
        if(cap>=len)
        {
            cout<<res<<endl;
            continue;
        }
        unordered_set<int> page;
        queue<int> LRU;
        for(int i=0;i<cap;i++)
        {
            page.insert(arr[i]);
            LRU.push(arr[i]);
        }
        for(int i=cap;i<len;i++)
        {
            if(page.find(arr[i])==page.end())
            {
                page.erase(LRU.front());
                page.insert(arr[i]);
                LRU.push(arr[i]);
                LRU.pop();
                res++;
            }
        }
        cout<<res<<endl;
    }
	return 0;
}