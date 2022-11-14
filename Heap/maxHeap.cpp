#include <iostream>
#include <vector>
using namespace std;

class minHeap{
    vector<int> heap;
    public:
    void push(int);
    void pop();
    int top();
    bool isempty();
    int size();
    static int at(int);
};

void minHeap :: push(int val){
    heap.push_back(val);
    int index = heap.size() -1;
    while (index)
    {
        int parent = (index - 1)/2;
        if (heap[index] > heap[parent]){
            int temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;
        }
        else break;
        index = parent;
    }
    
}

int minHeap :: top(){
    return heap[0];
}

void minHeap :: pop(){
    heap[0] = heap[heap.size() -1];
    int parent = 0, index = 1;
    while (index < heap.size()-1)
    {
        index = heap[index] > heap[index+1]? index: index+1;
        if (heap[index] > heap[parent]){
            int temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;
        }
        else break;
        parent = index;
        index = parent*2+1;
    }
    heap.pop_back();
}

bool minHeap :: isempty(){
    return heap.empty();
}

int minHeap :: size(){
    return heap.size();
}

int minHeap::at(int) {
    return 0;
}

int main(){
    minHeap pq;
    pq.push(5);
    pq.push(1);
    pq.push(3);
    pq.push(8);
    pq.push(7);
    pq.push(0);
    pq.push(2);

    while (!pq.isempty())
    {
        cout<<pq.top()<<' ';
        pq.pop();
    }
    
}