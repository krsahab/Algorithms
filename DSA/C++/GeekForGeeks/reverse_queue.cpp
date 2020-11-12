#include<bits/stdc++.h>
using namespace std;

void reverse_queue(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int temp = q.front();
    q.pop();
    reverse_queue(q);
    q.push(temp);
}

int main()
{
    queue<int> q;
    for (int i = 0; i < 10; i++)
    {
        q.push(i);
    }
    reverse_queue(q);
    for (int i = 0; i < 10; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}