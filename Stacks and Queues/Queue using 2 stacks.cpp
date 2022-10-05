#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

template <class T>
class Stack{
    public:
    vector<T> stack;

    void push(T n){
        stack.push_back(n);
    }

    void pop(){
        if (stack.size() == 0){
            cout<<"Stack Underflow Error";
            exit(0);
            return;
        }
        auto elem = stack.end() -1;
        stack.pop_back();
    }

    void display(){
        for(auto i = stack.rbegin(); i != stack.rend(); i++) cout<<*i<<' ';
    }

    T top(){
        return *(--stack.end());
    }

    int size(){
        return stack.size();
    }
};

class Queue{
    Stack<int> s1;
    Stack<int> s2;

    public:
    void enqueue(int val){
        s1.push(val);
    }

    void deque(){
        if(s1.size() == 0 && s2.size() == 0) return;

        if(s2.size() == 0){
            while(s1.size() != 0){
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    int front(){
        if(s1.size() == 0 && s2.size() == 0) return -1;

        if(s2.size() == 0){
            while(s1.size() != 0){
                s2.push(s1.top());
                s1.pop();
            }
        }

        return  s2.top();
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Queue q;
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(59);
    q.enqueue(7);

    q.deque();
    q.deque();
return 0;
}