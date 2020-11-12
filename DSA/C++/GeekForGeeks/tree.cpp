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

void addnode(node *root, int data, char dir)
{
    if(root == NULL)
    return;
    if(dir=='l')
    {
        while(root->left!=NULL)
        {
            root = root->left;
        }
        root->left = createNode(data);
    }
    if(dir=='r')
    {
        while(root->right!=NULL)
        {
            root = root->left;
        }
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

void preorder(node *root)
{
    if(root)
    {
        cout<<root->data<<endl;
        if(root->left)
        inorder(root->left);
        if(root->right)
        inorder(root->right);
    }
}

void postorder(node *root)
{
    if(root)
    {
        if(root->left)
        inorder(root->left);
        if(root->right)
        inorder(root->right);
        cout<<root->data<<endl;
    }
}

int no_node(node *head)
{
    if(head)
    {
        return (1+no_node(head->right)+no_node(head->left));
    }
    else
    return 0;
}

int no_leaf(node *head)
{
    if(head==NULL)
    return 0;
    if(head->left==NULL && head->right==NULL)
    return 1;
    else
    return (no_leaf(head->right)+no_leaf(head->left));
}

int no_noleaf(node *head)
{
    if(head==NULL)
    return 0;
    if(head->left==NULL && head->right==NULL)
    return 0;
    else
    return (1+no_noleaf(head->right)+no_noleaf(head->left));
}

int fullNode(node* head)
{
    if(head && (head->left || head->right))
    return (fullNode(head->right)+fullNode(head->left)+((head->left && head->right)?1:0));
    else
    return 0;
}

int height(node* head)
{
    if(head && (head->right || head->left))
    {
        int l = height(head->left);
        int r = height(head->right);
        return (1+((l>r)?l:r));
    }
    else if(head)
    return 1;
    else
    return 0;
}

int iscomplete(node *head)
{
    if(head==NULL)
    return 1;
    else if(!head->left && !head->right)
    return 1;
    else if(head->right && head->left)
    return (iscomplete(head->left) && iscomplete(head->right));
    else
    return 0;
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

void printlevel(node *root, int l)
{
    if(!root)
    return;
    else if(l==1)
    cout<<root->data<<" ";
    else if(l>1)
    {
        printlevel(root->left, l-1);
        printlevel(root->right, l-1);
    }
}

void leveltraverse(node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
        printlevel(root,i);
}

void BFS_traversal(node* root)
{
    if(!root)
    return;
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }
}

void insert(node *root, int key)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(!temp->left)
        {
            temp->left = createNode(key);
            break;
        }
        else
        q.push(temp->left);
        if(!temp->right)
        {
            temp->right = createNode(key);
            break;
        }
        else
        q.push(temp->right);
    }
}

int main()
{
    // node *head = createNode(50);
    // int num[] = {15,62,5,20,58,91,3,8,37,60,24};
    // for(int i = 0; i<11;i++)
    // {
    //     bst_addnode(head,num[i]);
    // }
    // inorder(head);
    // int noleaf = no_noleaf(head);
    // int leaf = no_leaf(head);
    // int nodes = no_node(head);
    // int fullnode = fullNode(head);
    // int h = height(head);
    // cout<<"Nodes: "<<nodes<<endl<<"leaves: "<<leaf<<endl<<"Noleaves: "<<noleaf<<endl;
    // cout<<"fullnode: "<<fullnode<<endl<<"Height: "<<h<<endl;
    // cout<<"BFS Traversal"<<endl;
    node *root = createNode(1);  
    root->left = createNode(2);  
    root->right = createNode(3);  
    root->left->left = createNode(4);  
    root->left->right = createNode(5);
    BFS_traversal(root);
}