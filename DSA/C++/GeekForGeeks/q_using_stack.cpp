#include<iostream>
#include<stack>
using namespace std;

class queue
{
    public:
        stack<int> s1, s2;
        void enqueue(int item)
        {
            s1.push(item);
        }
        int dequeue()
        {
            if(s2.empty())
            {
                if(s1.empty())
                {
                    cout<<"Queue is empty";
                    return 0;
                }
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            return s2.top();
        }
        void printqueue()
        {
            while(!s2.empty())
            {
                cout<<s2.top()<<endl;
                s2.pop();
            }
        }
};

int main()
{
    queue *q = new queue();
    for(int i=0;i<=10;i++)
    {
        q->enqueue(i);
    }
    q->dequeue();
    q->printqueue();
}