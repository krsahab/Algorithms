#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Stack
{
    queue <int> q;

    void pop()
    {
        if(q.empty())
        return;
        q.pop();
    }
    void push(int data)
    {
        int s = q.size();
        q.push(data);
        for(int i=0;i<s;i++)    
        {
            q.push(q.front());
            q.pop();
        }
    }
    int top()
    {
        if(q.empty())
        return -1;
        return q.front();
    }
};
int main()
{

}