#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int s;
	    cin>>s;
	    char ch;
	    int visited[256] = {0};
	    deque<char> st;
	    for(int i=0;i<s;i++)
	    {
	        cin>>ch;
	        if(!visited[ch])
	        {
	            cout<<ch<<" ";
	            st.push_back(ch);
	            visited[ch] = true;
	        }
	        else
	        {
	            while(!st.empty() && visited[st.front()])
	            st.pop_front();
	            if(!st.empty())
	            cout<<st.front()<<" ";
	            else
	            cout<<"-1"<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}