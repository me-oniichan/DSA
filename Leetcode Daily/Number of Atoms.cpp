#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        map<string, int> cur;
        int i = 0;
        while (i < formula.size()) {
            if (formula[i] == '(') {
                st.push(cur);
                cur.clear();
                i++;
            } else if (formula[i] == ')') {
                i++;
                int j = i;
                while (j < formula.size() && isdigit(formula[j])) j++;
                int count = (j == i) ? 1 : stoi(formula.substr(i, j - i));
                i = j;
                for (auto& p : cur) {
                    st.top()[p.first] += p.second * count;
                }
                cur = st.top();
                st.pop();
            } else {
                int j = i + 1;
                while (j < formula.size() && islower(formula[j])) j++;
                string name = formula.substr(i, j - i);
                i = j;
                j = i;
                while (j < formula.size() && isdigit(formula[j])) j++;
                int count = (j == i) ? 1 : stoi(formula.substr(i, j - i));
                i = j;
                cur[name] += count;
            }
        }
        string ans;
        for (auto& p : cur) {
            ans += p.first;
            if (p.second > 1) ans += to_string(p.second);
        }
        return ans;
    }
};
