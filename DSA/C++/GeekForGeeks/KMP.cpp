#include <bits/stdc++.h>

using namespace std;

int *lps;

int LPS(string s)
{
    lps = new int[s.length()];
    lps[0] = 0;
    for (int n = 1; n < s.length(); n++)
    {
        int len = lps[n - 1];
        if (s[n] == s[len])
            lps[n] = len + 1;
        else
        {
            if (len == 0)
                lps[n] = 0;
            else
            {
                while (len > 0 && s[n] != lps[len])
                    len = lps[len - 1];
                lps[n] = len;
            }
        }
    }
}

void KMP(string s, string pat)
{
    LPS(s);
    int i = 0;
    int matched = 0;
    int n = pat.length();
    int m = s.length();
    while (i < m)
    {
        if (s[i] == pat[matched])
        {
            i++;
            matched++;
        }
        if (matched == n)
        {
            cout << i - n << " ";
            matched = lps[n - 1];
        }
        if (i < m && s[i] != pat[matched])
        {
            if (matched == 0)
                i++;
            else
                matched = lps[matched - 1];
        }
    }
}

int main()
{
    string s = "ababcababaad";
    string pat = "ab";
    KMP(s, pat);
    return 0;
}