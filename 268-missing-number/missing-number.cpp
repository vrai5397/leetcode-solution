class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 6-4
        int n=nums.size();
        int totalsum=(n*(n+1))/2;
        int sum=0;
        for(int i=0;i<nums.size();i++){
           sum+=nums[i];
        }
        return totalsum-sum;
    }
};