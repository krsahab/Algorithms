#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<string> q;
    q.push("5");
    q.push("6");
    for (int i = 0; i < 10; i++)
    {
        cout<<q.front()<<" ";
        q.push(q.front()+"5");
        q.push(q.front()+"6");
        q.pop();
    }
    return 0;
}