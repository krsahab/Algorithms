#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool pelindrome(string s, int l, int r)
{
	if (l==r)
	{
		return true;
	}
	if (l>r)
	{
		return true;
	}
	if (s[l]!=s[r])
	{
		return false;
	}
	pelindrome(s,l+1,r-1);
}

int main() {
	string input_string;
	cout<<"Enter String";
	getline(cin,input_string);
	cout<<pelindrome(input_string,0,input_string.length()-1);
}
