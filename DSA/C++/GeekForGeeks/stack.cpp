#include<iostream>
#include<stack>

using namespace std;

void showstack(stack <int> t)
{
    while(!t.empty())
    {
        cout<<t.top()<<endl;
        t.pop();
    }
}
int main()
{
    stack<int> s;
    for(int i=0;i<=10;i++)
    {
        s.push(i);
    }
    showstack(s);
}