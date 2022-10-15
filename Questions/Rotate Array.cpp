// Problem Statement : https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for (int i = 0; i < n; i++)

    void rotate(vector<int> &nums, int k){
        k%=nums.size();
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
        reverse(nums.begin()+k, nums.end());
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
    int last = array[array.size() - 1];
    array.pop_back();
    rotate(array, last);
    for (auto i : array)
    {
        cout << i << ' ';
    }
    return 0;
}