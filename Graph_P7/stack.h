#include <iostream>
#define max 100
using namespace std;


template <class T>
class Stack
{
    T stack[max];
    int top;
    public:
        void push(T);
        T pop();
        void display();
        bool underflowCondition();
        bool overflowCondition();
        int getSize();
        Stack()
        {
            top=-1;
        }
};
template <class T>
bool Stack<T>::underflowCondition()
{
    if(top == -1)
        return true;
    return false;
}
template <class T>
bool Stack<T>::overflowCondition()
{
    if(top==max)
        return true;
    return false;
}
template <class T>
void Stack<T>::push(T pushValue)
{
    /*if(overflowCondition)
    {
        return -1;
    }*/
    top++;
    stack[top]=pushValue;
    return ;
}
template <class T>
T Stack<T>::pop()
{
    if(top==-1)
    {
        return NULL;
    }
    return stack[top--];
    
}
template <class T>
void Stack<T>::display()
{
    int temp = top;
    while(temp!=-1)
    {
        cout<<stack[temp]->data;
        temp--;
        cout<<endl;
    }
}