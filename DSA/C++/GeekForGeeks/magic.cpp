#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string s)
{
    int l=0, r=s.size()-1;
    while(l<r)
    {
        if(s[l]!=s[r])
        return false;
        l++;
        r--;
    }
    return true;
}
void magic_numbers(int n)
{
    queue<string> q;
    q.push("4");
    q.push("5");
    int count = 0;
    while(count<n)
    {
        if(ispalindrome(q.front()))
        {
            count++;
            cout<<q.front()<<endl;
        }
        q.push(q.front()+"4");
        q.push(q.front()+"5");
        q.pop();
    }
}

int main()
{
    magic_numbers(7);
    return 0;
}