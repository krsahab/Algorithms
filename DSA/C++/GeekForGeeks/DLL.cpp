#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    node *pre;
    node *next;
    node(int d, node* p = NULL, node*n = NULL):data(d),pre(p),next(n){}
}node;

void print(node *list)
{
    node *ptr = list;
    while(ptr!=NULL && ptr->next!=NULL)
    {
        cout<<ptr->data<<" "<<ptr->next<<" "<<ptr->pre<<endl;
        ptr=ptr->next;
    }
}

int main()
{
    node *head = new node(0,NULL,NULL);
    node *temp = head;
    for(int i=1;i<=5;i++)
    {
        node *ptr = new node(i,temp,NULL);
        temp->next = ptr;
        temp = ptr;
    }
    print(head);
    return 0;
}