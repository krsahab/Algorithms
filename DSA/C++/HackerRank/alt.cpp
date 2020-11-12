#include<bits/stdc++.h>
using namespace std;

int alternatingCharacters(string s) {
    int counter = 0;
    char st = s[0];
for(int i=1;i<s.size();i++)
{
    if(s[i]==st)
    {
        s.erase(s.begin()+i);
        counter++;
        i--;
    }
    st = s[i];
}
return counter;
}

int main()
{
    cout<<alternatingCharacters("AAAA");
    return 0;
}