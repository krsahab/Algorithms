#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
    cout<<"Enter expression"<<endl;
    string str;
    getline(cin,str);
    stack<int> s;
    string::iterator it;
    string op = "+-*/";
    for(it = str.begin();it!=str.end();it++)
    {
        if(isdigit(*it))
        {
            s.push((int)*it-'0');
        }
        if(op.find(*it)!=string::npos)
        {
            int op1, op2;
            switch (*it)
            {
            case '+':
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                s.push((char)(int)op1+(int)op2);
                break;
            case '-':
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                s.push((char)(int)op2-(int)op1);
                break;
            case '*':
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                s.push((char)(int)op2*(int)op1);
                break;
            case '/':
                op1 = s.top();
                s.pop();
                op2 = s.top();
                s.pop();
                s.push((char)(int)op2/(int)op1);
                break;
            default:
                break;
            }
        }
    }
    cout<<s.top();
}