#include<bits/stdc++.h>
using namespace std;

int priority(char c)
{
    switch (c)
    {
        case '(':
        return 6;
        case '^':
        return 5;
        case '/':
        return 4;
        case '*':
        return 3;
        case '+':
        return 2;
        case '-':
        return 1;
        default:
        return 0;
    }
}

void infixToPostfix(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]>=97 && s[i]<=122)
        {
            cout<<s[i];
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top()!='(')
            {
                cout<<st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && st.top()!='(' && priority(st.top())>priority(s[i]))
            {
                cout<<st.top();
                st.pop();
            }
            st.push((char)s[i]);
        }
        
    }
    while (!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}

int main()
{
    string input = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(input);
    return 0;
}