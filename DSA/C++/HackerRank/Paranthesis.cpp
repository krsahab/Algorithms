#include<bits/stdc++.h>
using namespace std;

bool match(char c,stack<char> &st)
{
    if(st.empty())
    return false;
    switch(c)
    {
        case ')':
        if(st.top()=='(')
        return true;
        else
        return false;
        case '}':
        if(st.top()=='{')
        return true;
        else
        return false;
        case ']':
        if(st.top()=='[')
        return true;
        else
        return false;
        default:
        return false;
    }
}
string isBalanced(string s) {
    stack<char> st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        st.push(s[i]);
        else
        {
            if(!match(s[i],st))
            return "NO";
            else
            st.pop();
        }
    }
    if(st.size()>0)
    return "NO";
    return "YES";
}

int main()
{
    cout<<isBalanced("{{{{{{{[[(())]]}}}");
    return 0;
}