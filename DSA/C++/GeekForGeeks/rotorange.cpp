#include <bits/stdc++.h>
using namespace std;

bool isvalid(int r, int c, int i, int j)
{
    if(i>=0 && i<r && j>=0 && j<c)
    return true;
    else
    return false;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int r, c;
	    cin>>r>>c;
	    int arr[r][c];
	    queue<pair<int,int>> q;
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            cin>>arr[i][j];
	            if(arr[i][j]==2)
	            q.push(pair<int,int>(i,j));
	        }
	    }
	    int xd[] = {-1,1,0,0}; 
	    int yd[] = {0,0,-1,1};
	    int row,col,count=0;
	    while(!q.empty())
	    {
	        int s = q.size();
	        for(int i=0;i<s;i++)
	        {
	            count++;
	            row = q.front().first;
	            col = q.front().second;
	            q.pop();
	            for(int j=0;j<4;j++)
	            {
	                if(isvalid(r,c,row+xd[j],col+yd[j]))
	                {
	                    if(arr[row+xd[j]][col+yd[j]]==1)
	                    {
	                        arr[row+xd[j]][col+yd[j]]=2;
	                        q.push(pair<int,int>(row+xd[j],col+yd[j]));
	                    }
	                }
	            }
	        }
	    }
	    bool flag = false;
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            if(arr[i][j]==1)
	            {
	                cout<<"-1"<<endl;
	                flag = true;
	                break;
	            }
	        }
	        if(flag)
	        break;
	    }
	    if(!flag)
	    cout<<count<<endl;
	}
	return 0;
}