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
};

int main(){
    vector<int> arr{1,2,3,4,5,6, 7};
    SegTree tree(arr, 0, arr.size()-1, 0);
    for(int i = 0; i < 2*arr.size()-1; i++){
        cout<<tree.at(i)<<' ';
    }
return 0;
}