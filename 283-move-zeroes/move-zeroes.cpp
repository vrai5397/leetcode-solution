class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         // brute force
         vector<int> ans;
         int count=0;
         for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)
            ans.push_back(nums[i]);
            else
            count++;
         }
         for(int i=0;i<count;i++)
         ans.push_back(0);
         nums=ans;
    }
};