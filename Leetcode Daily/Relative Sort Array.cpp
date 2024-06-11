#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mapping;
        for(int i=0; i < arr2.size(); i++){
            mapping[arr2[i]] = i;
        }

        sort(arr1.begin(), arr1.end(), [mapping](int a, int b){
            return (mapping.count(a)? mapping.at(a) : 10000000+a ) < (mapping.count(b)? mapping.at(b): 10000000+b);
        });
        return arr1;
    }
};
