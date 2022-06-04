#include <iostream>
#include <vector>
using namespace std;

class SegTree{
  public:
  vector<int> tree;
  SegTree(){};
  SegTree(int arr[], int size){
    build(arr, size);
  }
  int at(int i){
    return tree.at(i);
  }
  void build(int arr[], int size){
    tree.resize(size*2 -1);
    for (int i = size-1; i < 2*size-1; i++){
      tree[i] = arr[i-size+1];
    }
    for(int i = size-2; i >= 0; i--){
      tree[i] = tree[i<<1|1] + tree[(i<<1)+2];
    }
  }
};
 
int main(){
    int arr[7] = {1,2,3,4,5,6,7};
    SegTree tree(arr, 7);
    for (int i = 0; i < 13; i++){
        cout<<tree.at(i)<<' ';
    }
return 0;
}