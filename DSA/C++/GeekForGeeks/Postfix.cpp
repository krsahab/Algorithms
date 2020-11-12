#include<iostream>
#include<stack>
#include<string>
using namespace std;

int prec(char c)
{
    if(c=='^')
    return 3;
    else if(c=='*'  || c=='/')
    return 2;
    else if(c=='+' || c=='-')
    return 1;
    else
    {
        return -1;
    }
}
int main()
{
    stack<char> s;
    string str;
    string op = "+-*()/^";
    cout<<"Enter a string"<<endl;
    getline(cin,str);
    string::iterator it;
    for(it=str.begin();it!=str.end();it++)
    {
        if(isdigit(*it))
        {
            cout<<*it;
        }
        else if(*it=='(')
        s.push(*it);
        else if(*it==')')
        {
             while(s.top()!='(' && (!s.empty()))
             {
                 cout<<s.top();
                 s.pop();
             }
             if(s.top()=='(')
             s.pop();
        }
        else if(op.find(*it)!=string::npos)
        {
            while((!s.empty()) && (prec(s.top())>prec(*it)))
            {
                cout<<s.top();
                s.pop();
            }
            s.push(*it);
        }
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}