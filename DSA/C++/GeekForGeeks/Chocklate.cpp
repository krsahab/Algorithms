#include <bits/stdc++.h>
using namespace std;

vector<string> getDecision(int a , int b)
{
    vector<string> result;
    while(a!=b)
    {
        if(b%2!=0)
        {
            b+=1;
            result.push_back("eat");
        }
        else
        {
            if(b>a)
            {
                b=b/2;
                result.push_back("overflow");
            }
            else
            {
                b+=1;
                result.push_back("eat");
            }
        }
    }
    reverse(result.begin(),result.end());
    return result;
}

int main()
{
    vector<string> result;
    result = getDecision(5,8);
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    
    return 0;
}