#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> hmap;
    vector<bool> valid;
    int ans;
    void concatinate(vector<string> &arr, int i, int len){
        if (arr.size() == i){
            ans = max(len, ans);
            return;
        }

        bool flag = true;

        for(char i : arr[i]){
            if(hmap[i - 'a']){
                flag = false;
                break;
            }
        }

        // don't take
        concatinate(arr, i+1, len);

        if (flag && valid[i]){
            for(char i : arr[i]){
                hmap[i-'a'] = true;
            }
            len+=arr[i].size();
            concatinate(arr, i+1, len);

            //restoring state
            for(char i: arr[i]){
                hmap[i-'a']=false;
            }
        }
    }
    int maxLength(vector<string>& arr) {
            valid.resize(26, true);
            hmap.resize(26);
        ans = 0;

        for(int i=0; i < arr.size(); i++){
            for(char j : arr[i]){
                if (hmap[j-'a']){
                    valid[i] = false;
                    break;
                }
                hmap[j-'a']=true;
            }

            for_each(hmap.begin(), hmap.end(), [](bool &k){k=false;});
        }

        concatinate(arr, 0, 0);

        return ans;
    }
};