class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
       for(int i=0;i<nums.size()-2;i++){
        if(i > 0 && nums[i] == nums[i-1])
    continue;
         int target=-nums[i];
         unordered_map<int,int> mp;
         int j=i+1;
         int k=nums.size()-1;
         while(j<k){
            if(nums[j]+nums[k]>target)
            k--;
           else if(nums[j]+nums[k]<target)
           j++;
           else{
             while(j<k&&nums[j]==nums[j+1])
             j++;
             while(j<k&&nums[k]==nums[k-1])
             k--;
               vector<int> helper;
            helper.push_back(nums[i]);
            helper.push_back(nums[j]);
            helper.push_back(nums[k]);
            ans.push_back(helper);
             j++;
             k--;
           }
         }
       } 
       return ans;
    }
};