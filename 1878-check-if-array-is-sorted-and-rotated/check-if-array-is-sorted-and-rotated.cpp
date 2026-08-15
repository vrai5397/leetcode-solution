class Solution {
public:
    bool check(vector<int>& nums) {
        // sorted and rotated array will only have one position
        // where nums[i]>nums[i+1]
        int count=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%n])
            count++;
        }
        if(count>1) return false;
        return true;
    }
};