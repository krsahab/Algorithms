#include<bits/stdc++.h>
using namespace std;

string isValid(string s) {
    int fre[26] = {0};
    unordered_map<int,int> mp;
    for(int i=0;i<s.size();i++)
    {
        fre[s[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(fre[i]==0)
        continue;
        if(mp.find(fre[i])!=mp.end())
        {
            mp[fre[i]]++;
        }
        else
        mp[fre[i]]=1;
    }
    if(mp.size()==1)
    return "YES";
    if(mp.size()>2)
    return "NO";
    if(mp[1]==1)
    return "YES";
    unordered_map<int,int> :: iterator it;
    it = mp.begin();
    int sec = it->first;
    it++;
    if(abs(sec - it->first)==1)
    return "YES";
    return "NO";
}

int main()
{
    cout<<isValid("aabbccddeefghi");
    return 0;
}