#include<bits/stdc++.h>
using namespace std;

class box
{
    public:
    int h;
    int w;
    int l;
    box(int height, int width, int length)
    {
        h=height;
        w=width;
        l=length;
    }
};

int findMaxHeight(vector<box> &boxes, int n)
{
    int res[n]={0};
    for(int i=0;i<n;i++)
    {
        res[i]=boxes[i].l;
    }
    int ans=boxes[0].l;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if((boxes[i].h<boxes[j].h && boxes[i].w<boxes[j].w) || (boxes[i].h<boxes[j].w && boxes[i].w<boxes[j].h))
            res[i] = max(res[i],res[j]+boxes[i].l);
        }     
        ans = max(ans,res[i]);   
    }
    return ans;
    /*if(n==0)
    return 0;
    if(last==-1 || (boxes[n-1].h>boxes[last].h && boxes[n-1].w>boxes[last].w) || (boxes[n-1].h>boxes[last].w && boxes[n-1].w>boxes[last].h))
    {
        return max(boxes[n-1].l+findMaxHeight(boxes,n-1,n-1),findMaxHeight(boxes,n-1,last));
    }
    else
    return findMaxHeight(boxes,n-1,last);*/
}

bool mycomp(box b1, box b2)
{
    return b1.h*b1.w>b2.h*b2.w;
}

int maxHeight(int height[],int width[],int length[],int n)
{
    vector<box> boxes;
    for(int i=0;i<n;i++)
    {
        boxes.push_back(box(height[i],width[i],length[i]));
        boxes.push_back(box(length[i],height[i],width[i]));
        boxes.push_back(box(length[i],width[i],height[i]));
    }
    sort(boxes.begin(),boxes.end(),mycomp);
    return findMaxHeight(boxes,n*3);
}

int main()
{
    int n = 4;
    int height[] = {4,1,4,10};
    int width[] = {6,2,5,12};
    int length[] = {7,3,6,32};
    cout<<maxHeight(height,width,length,n);
    return 0;
}