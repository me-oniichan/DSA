#include <iostream>
#include <stdlib.h>
using namespace std;

class Queue{
    int *ptr = (int*)malloc(sizeof(int));
    int size = 0;
    public:
        void push(int);
        int pop();
        int seek(int);
        bool isEmpty();
        void display();
};

void Queue :: push(int val){
    ptr = (int*)realloc(ptr, ++size*sizeof(int));
    ptr[size-1] = val;
}

void Queue :: display(){
    for (size_t i = 0; i < size; i++)
    {
        cout<<ptr[i]<<' ';
    }
    cout<<endl;
}

int Queue::pop(){
    if (size == 0) return -1;
    size--;
    int val = *ptr;
    ptr = ptr+1;
    delete (ptr-1);
    return val;
}

int Queue:: seek(int val){
    return ptr[val];
}

bool Queue :: isEmpty(){
    if (size > 0) return false;
    return true;
}

int main(){
    Queue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    queue.display();

    queue.pop();
    queue.pop();
    queue.display();

    cout<<queue.seek(2)<<endl;
    cout<<queue.isEmpty()<<endl;
return 0;
}