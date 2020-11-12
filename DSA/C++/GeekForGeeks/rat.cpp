#include<bits/stdc++.h>
using namespace std;

int maze[4][4];
int sol[4][4];

void printmatrix()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cout<<sol[i][j];
}

bool issafe(int i, int j)
{
    if(i>=0&&j>=0&&i<4&&j<4)
    if(maze[i][j]==1)
    return true;
    return false;
}

bool findpath(int i,int j)
{
    if(i==3 && j==3)
    {
        sol[i][j]=1;
        return true;
    }
    if(issafe(i,j))
    {
        sol[i][j]=1;
        if(findpath(i+1,j)==true)
        return true;
        else if(findpath(i,j+1)==true)
        return true;
        sol[i][j]=0;
    }
    return false;
}

int main()
{
    if(findpath(0,0)==true)
    printmatrix();
    else
    cout<<-1;
    return 0;
}