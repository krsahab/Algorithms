#include<bits/stdc++.h>

using namespace std;

class kstack
{
    int *arr;
    int *next;
    int *k;
    int freetop;
    int size;

    public:
    int capacity;
    kstack(int capacity, int no)
    {
        capacity = capacity;
        next = new int[capacity];
        arr = new int[capacity];
        for(int i=0; i<capacity; i++)
            next[i] = i+1;
        next[capacity-1] = -1;
        k = new int[no];
        for (int i = 0; i < no; i++)
            k[i] = -1;
        
        size = 0;
        freetop = 0;
    }
    void push(int data, int st)
    {
        if(size==capacity)
        return;
        size++;
        int i = freetop;
        freetop = next[i];
        next[i] = k[st];
        arr[i]=data;
        k[st] = i;
    }

    int pop(int st)
    {
        if(size==0)
        return -1;
        int top = arr[k[st]];
        k[st] = next[k[st]];
        next[k[st]] = freetop;
        freetop = k[st];
        return top;
    }
};

int main()
{
    // Let us create 3 stacks in an array of size 10 
    int k = 3, n = 10; 
    kstack ks(n, k); 
  
    // Let us put some items in stack number 2 
    ks.push(15, 2); 
    ks.push(45, 2); 
  
    // Let us put some items in stack number 1 
    ks.push(17, 1); 
    ks.push(49, 1); 
    ks.push(39, 1); 
  
    // Let us put some items in stack number 0 
    ks.push(11, 0); 
    ks.push(9, 0); 
    ks.push(7, 0); 
  
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl; 
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl; 
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl; 
  
    return 0; 
}