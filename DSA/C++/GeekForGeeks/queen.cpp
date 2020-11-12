#include<bits/stdc++.h>
using namespace std;

int board[4][4];

bool issafe(int i,int j)
{
    for(int k=0;k<j;k++)
    if(board[i][j]==1)
    return false;

    for(int r=i,c=j;r>=0&&j>=0;r--,c--)
    if(board[r][c]==1)
    return false;

    for(int r=i,c=j;r<4&&j>=0;r++,c--)
    if(board[r][c]==1)
    return false;

    return true;
}

bool findmat(int col)
{
    if(col==4)
    return true;
    for (int i = 0; i < 4; i++)
    {
        if(issafe(i,col))
        {
            board[i][col] = 1;
            if(findmat(col+1))
            return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    if(findmat(0))
    cout<<"found";
    return 0;
}