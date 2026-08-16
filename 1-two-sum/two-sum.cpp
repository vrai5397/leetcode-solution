class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // it can be solve using map
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                // found in map
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                break;
            }
            else
            mp[nums[i]]=i;
        }
        return ans;
    }
};