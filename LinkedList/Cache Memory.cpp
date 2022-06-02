//Problem Statement : https://www.hackerrank.com/challenges/abstract-classes-polymorphism/
// Implementation of cache memory using doubly linked list

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache: public Cache{
    public:
    int size = 0;
    LRUCache(int cap){
        cp = cap;
    };
    
    void set(int, int);
    int get(int);
};

void LRUCache :: set(int key, int val){
    if (mp.empty()){
        head = new Node(key, val);
        tail = head;
        mp[key] = head;
        size++;
        return;
    }
    
    if (mp.find(key) == mp.end()){
        head->prev = new Node(NULL, head, key, val);
        head = head->prev;
        mp[key] = head;
        size++;
        if(cp < size){
            mp.erase(tail->key);
            tail = tail->prev;
            size--;
        }
    }
    else {
        mp[key]->value = val;
    }
}

int LRUCache :: get(int key){
    int res = (mp.find(key) == mp.end())? -1: mp[key]->value;
    return res;
}

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
