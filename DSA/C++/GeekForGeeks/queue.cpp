#include<iostream>
using namespace std;

class queue
{
    int rear, front, size, capacity;
    int *arr;
    public:
        queue(int c)
        {
            capacity = c;
            rear = c-1;
            front = size = 0;
            arr = new int(capacity*sizeof(int));
        }

        void enqueue(int item)
        {
            if(this->size==this->capacity)
            {
                cout<<"Queue is full"<<endl;
                return;
            }
            this->arr[this->size++]=item;
        }

        int dequeue()
        {
            if(this->size==0)
            {
                cout<<"Queue is empty"<<endl;
                return 0;
            }
            return this->arr[this->size---1];
        }

        void print()
        {
            for(int i=0; i<this->size;i++)
            {
                cout<<this->arr[i]<<endl;
            }
        }
};


int main()
{
    queue *q = new queue(5);
    for(int i = 0;i<10;i++)
    {
        q->enqueue(i);
    }
    q->print();
}