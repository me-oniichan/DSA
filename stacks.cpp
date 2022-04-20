#include <iostream>
#include <stdlib.h>
using namespace std;

class Stack
{
    int *ptr = (int *)malloc(sizeof(int));

public:
    int size = 0;
    void push(int);
    int pop();
    int seek();
    void display();
    bool isEmpty();
};

bool Stack :: isEmpty(){
    if (size == 0) return true;
    else return false;
}

void Stack ::push(int val)
{
    size++;
    ptr = (int *)realloc(ptr, size * sizeof(int));
    ptr[size - 1] = val;
    return;
}

void Stack ::display()
{
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << ' ';
    }
    return;
}

int Stack :: pop(){
    if(size > 0){
        int data;
        size--;
        data = ptr[size];
        ptr = (int*)realloc(ptr, sizeof(int)*size);
        return data;
    }
    return -1;
}

int Stack :: seek(){
    return ptr[size];
}

int main()
{
    Stack test_stack;
    test_stack.push(1);
    test_stack.push(2);
    test_stack.push(3);
    test_stack.push(4);
    test_stack.push(5);

    cout<<test_stack.pop()<<" popped"<<endl;
    cout<<test_stack.pop()<<" popped"<<endl;
    cout<<test_stack.pop()<<" popped"<<endl;
    test_stack.display();

    return 0;
}