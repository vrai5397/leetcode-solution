class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 1 2 6 24
        //24 24 12 4 
        vector<int> prefix(nums.size(),0);
        vector<int> suffix(nums.size(),0);
        prefix[0]=nums[0];
        suffix[nums.size()-1]=nums[nums.size()-1];
        for(int i=1;i<nums.size()-1;i++){
            prefix[i]=nums[i]*prefix[i-1];
            suffix[nums.size()-1-i]=nums[nums.size()-1-i]*suffix[nums.size()-i];
        }
       for(int i=0;i<nums.size();i++){
           if(i==0)
           nums[i]=suffix[i+1];
           else if(i==nums.size()-1)
           nums[i]=prefix[i-1];
           else
            nums[i]=prefix[i-1]*suffix[i+1];
       }
       return nums;
    }
};