class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // nlogn
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};