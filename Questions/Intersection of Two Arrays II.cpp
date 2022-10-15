#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fii for (int i = 0; i < n; i++)

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map1;
    for(int i:nums1) map1[i]++;
    vector<int> intersection;

    for(int i : nums2){
        if (map1[i]>0){
            intersection.push_back(i);
            map1[i]--;
        }
    }
    return intersection;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> array;
    vector<int> array2;
    int elem;
    while (cin >> elem) array.push_back(elem);

    for (auto i : array)
    {
        cout << i << ' ';
    }
    return 0;
}