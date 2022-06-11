#include <bits/stdc++.h>
using namespace std;
 
int mid(int start, int end){
    return (start+end)/2;
}

class SegTree{
    public:
    vector<int> tree;

    SegTree(vector<int> &arr, int s, int e, int i){
        tree.resize(2*(e-s)+1);
        build(arr, s,e,i);
    }

    int build(vector<int> &arr, int s, int e, int i){
        if(s >= e){
            return tree[i] = arr[s];
        }
        
        int m = mid(s,e);
        return tree[i] = build(arr, s,m, i<<1|1) + build(arr, m+1, e, (i<<1)+2);
    }

    int at(int i){
        return tree[i];
    }
    int size(){
        return tree.size();
    }

    int get(int, int, int);
    int getUtil(int,int,int,int, int);
    void update(int);
};

int SegTree :: get(int start, int end, int max_size){
    if (start < 0 || end > tree.size()/2 || start > end) {cout<<"invalid input"; return -1;}
    return getUtil(0, max_size-1, start, end, 0);
}

int SegTree :: getUtil(int start, int end, int qs, int qe, int i){
    if (start >= qs && end <= qe) return tree[i];   
    else if (qs > end || qe < start) return 0;

    int m = mid(start, end);
    return getUtil(start, m, qs, qe, i<<1|1) + getUtil(m+1, end, qs, qe, (i<<1)+2);
}

int main(){
    vector<int> arr{1,2,3,4,5,6, 7};
    SegTree tree(arr, 0, arr.size()-1, 0);
    cout<<tree.get(0, 5, arr.size());
return 0;
}