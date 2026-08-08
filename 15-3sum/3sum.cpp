class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // first we have to sort
        // when asked about index we cannot sort
        // when asked about value we can sort
       sort(nums.begin(),nums.end());
       vector<vector<int>> ans;
       for(int i=0;i<nums.size();i++){
          if(i>0 && nums[i]==nums[i-1])
          continue;
          int target=-nums[i];
          int j=i+1;
          int k=nums.size()-1;
          while(j<k){
        if(nums[j]+nums[k]>target)
        k--;
        else if(nums[j]+nums[k]<target)
        j++;
        else{ // equal target
            while(j<k&&nums[j]==nums[j+1]) // skip duplicate
            j++;
            while(j<k&&nums[k]==nums[k-1]) // skip duplicate
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