class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for(auto i:nums){
            x^=i;
        }
        int mask=1;
        while((mask&x)==0){
            mask<<=1;
        }
        int a=0,b=0;
        for(auto i:nums){
            if((mask&i)==0){
                a^=i;
            }else{
                b^=i;
            }
        }
        return {a,b};
    }
};
