class Solution {
public:
int solve(vector<int>& nums,int prev,int curr,vector<vector<int>>& dp){
    //  base case 
    if(curr>=nums.size())
    return 0;
    if(dp[prev+1][curr]!=-1)
    return dp[prev+1][curr];
    int include=-1e9;
    if(prev==-1||nums[curr]>nums[prev]){
        include=1+solve(nums,curr,curr+1,dp);
    }
    int exclude=solve(nums,prev,curr+1,dp);
    return dp[prev+1][curr]=max(include,exclude);

}
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return solve(nums,-1,0,dp);
    }
};