//Inssertion Deletion in a Heap
//Problem statement: https://www.hackerrank.com/challenges/qheap1/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
int q; vector<long> heap;
cin>>q;
int option;
long val;
while (q--) {
    cin>>option;
    if (option == 1){
        cin>>val;
        // int ind = lower_bound(heap.begin(), heap.end(), val)- heap.begin();
        heap.insert(lower_bound(heap.begin(), heap.end(), val), val);
    }
    else if(option == 2){
            cin>>val;
            heap.erase(lower_bound(heap.begin(), heap.end(), val));
    }
    else {
        cout<<heap.at(0)<<endl;
    }
}
    return 0;
}
