class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // brute force
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                // found in the map
                  ans.push_back(mp[target-nums[i]]);
                  ans.push_back(i+1);
                  break;
            }
            mp[nums[i]]=i+1;
        }
        return ans;
    }
};