class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int mod=0;
        vector<bool> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            mod=((mod*2)+nums[i])%5;
               ans[i]=(mod==0);
        }
        return ans;
    }
};