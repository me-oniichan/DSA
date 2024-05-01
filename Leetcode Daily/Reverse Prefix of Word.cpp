#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int i = 0;
        while(i < n && word[i] != ch) i++;
        if(i == n) return word;
        reverse(word.begin(), word.begin() + i + 1);
        return word;
    }
};
