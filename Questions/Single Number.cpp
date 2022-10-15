//Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/    

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for (int i = 0; i < n; i++)

    int singleNumber(vector<int> &nums){
        int res = 0;
        for(int i : nums) res^=i;
        return res;
    }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> array;
    int elem;
    while (cin >> elem)
    {
        array.push_back(elem);
    }
    singleNumber(array);
    for (auto i : array)
    {
        cout << i << ' ';
    }
    return 0;
}