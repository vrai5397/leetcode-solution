class Solution {
public:
int solve(vector<int>& nums,int i,vector<int>& dp){
    // base case
    if(i==0)
    return dp[i]=nums[i];
    if(i<0) return 0;
    if(dp[i]!=-1)
    return dp[i];
    int exclude=solve(nums,i-1,dp);
    int include=nums[i]+solve(nums,i-2,dp);

    return dp[i]=max(exclude,include);
}
    int rob(vector<int>& nums) {
        // we will follow pick and not pick strategy
        vector<int> dp(nums.size(),-1);
        return solve(nums,nums.size()-1,dp);
    }
};