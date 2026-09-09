class Solution {
public:
int solve(vector<int>& nums,int start,int end){
    // what to do
   
    vector<int> dp(end+1,0);
       dp[start]=nums[start];
    for(int i=start+1;i<=end;i++){
        int exclude=dp[i-1];
        int include=nums[i];
        if(i>=2)
         include=nums[i]+dp[i-2];
        dp[i]=max(include,exclude);
    }

 
  return dp[end];
}
    int rob(vector<int>& nums) {
         if(nums.size()==1)
         return nums[0];
         int n=nums.size();
        return max(solve(nums,0,n-2),solve(nums,1,n-1));
    }
};