#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        int ans = 0;
        bool odd = false;
        for (auto p : freq) {
            if (p.second % 2 == 0) {
                ans += p.second;
            } else {
                ans += p.second - 1;
                odd = true;
            }
        }
        return ans + odd;
    }
};
