#include<bits/stdc++.h>
using namespace std;

int makeAnagram(string a, string b) {
int arr1[256] = {0};
int arr2[256] = {0};
int i = 0;
while(i<a.size() && i<b.size())
{
    arr1[a[i]]++;
    arr2[b[i]]++;
    i++;
}
while(i<a.size())
{
    arr1[a[i]]++;
    i++;
}
while(i<b.size())
{
    arr2[a[i]]++;
    i++;
}
int res = 0;
for(int j=0;j<256;j++)
{
    res = res+(abs(arr1[j]-arr2[j]));
}
return res;
}
int main()
{
    cout<<makeAnagram("fcrxzwscanmligyxyvym", "jxwtrhvujlmrpdoqbisbwhmgpmeoke");
    return 0;
}