#include<iostream>
#include<queue>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

node* createNode(int data)
{
    //node *newnode = (node *)malloc(sizeof(node));
    node* newnode = new node;
    newnode->right = newnode->left = NULL;
    newnode->data = data;
    return newnode;
}

void bst_addnode(node *root, int data)
{
    if(root->data>data)
    {
        if(root->left)
        bst_addnode(root->left, data);
        else
        root->left = createNode(data);
    }
    if(root->data<=data)
    {
        if(root->right)
        bst_addnode(root->right, data);
        else
        root->right = createNode(data);
    }
}

void inorder(node *root)
{
    if(root)
    {
        if(root->left)
        inorder(root->left);
        cout<<root->data<<endl;
        if(root->right)
        inorder(root->right);
    }
}

node* max(node *head)
{
    while(head->right)
    head = head->right;
    return head ;
}

node* min(node* head)
{
    while(head->left)
    head = head->left;
    return head;
}

void delete_node(node* head)
{
    if(!head)
    return;
    else if(!head->left && !head->right)
    free(head);
    else if(head->right)
    {
        node* m = min(head->right);
        head->data = m->data;
        delete_node(m);
    }
    else if(head->left)
    {
        node* m = max(head->left);
        head->data = m->data;
        delete_node(m);
    }
}

int main()
{
    node *head = createNode(1);
    for (int i = 0; i < 6; i++)
    {
        bst_addnode(head,i+2);
    }
    delete_node(head);
    inorder(head);
}