//Problem Statement : https://leetcode.com/problems/sort-characters-by-frequency/

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        multimap<int, char, greater<int>> sortedmap;
        for(char i: s) m[i]++;

        for(auto i : m){
            sortedmap.insert({i.second, i.first});
        }
        s.resize(0);
        for(auto i : sortedmap){
            for(int j =0; j<i.first; j++) s.push_back(i.second);
        }

        return s;
    }
}; 
 
int main(){
 
return 0;
}