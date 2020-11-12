#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class stack_queue
{
    int size;
    queue<int> q1,q2;
    public:
    stack_queue()
    {
        size = 0;
    }
    void push(int data)
    {
        size++;
        q2.push(data);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.swap(q2);
    }
    void pop()
    {
        if(q1.empty())
        return;
        q1.pop();
        size--;
    }
    int top()
    {
        if(q1.empty())
        return -1;
        return q1.front();
    }
};
int main()
{
    stack_queue s;
    for(int i=1;i<10;i++)
    {
        s.push(i);
    }
    for(int i=1;i<10;i++)
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}