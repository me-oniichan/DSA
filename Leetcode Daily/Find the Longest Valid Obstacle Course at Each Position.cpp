#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int size = obstacles.size();
        vector<int> course, ans(size, 1);

        int j=0;
        for(int i : obstacles){
            int index = upper_bound(course.begin(), course.end(), i)  - course.begin();
            if(index == course.size()) course.push_back(i);
            else course[index] = i;

            ans[j++] = index+1;
        }
        return ans;
    }
};