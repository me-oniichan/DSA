//Problem Statement : https://leetcode.com/problems/search-a-2d-matrix/?envType=study-plan&id=algorithm-ii

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for(int i = 0; i < n; i++)

class Solution {
public:
    int n;
    bool binarySearch(int start, int end, int& val, vector<int>& array){
        if(start > end) return 0;
        int mid = (start+end)/2;
        if (array[mid] == val) return true;
        else if (array[mid] < val) return binarySearch(mid+1, end, val, array);
        else return binarySearch(start, mid-1, val, array);
    }

    bool binaryVec(int start, int end, int&target, vector<vector<int>>& matrix){
        if(start > end) return 0;
        int mid = (start+end)/2;
        if (matrix[mid][0]<=target && matrix[mid][n]>=target) return binarySearch(0, n, target, matrix[mid]);
        else if (matrix[mid][0] > target) return binaryVec(start, mid-1, target, matrix);
        else return binaryVec(mid+1, end, target, matrix);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        n = matrix[0].size()-1;
        return binaryVec(0, matrix.size()-1, target, matrix);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
return 0;
}