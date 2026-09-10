class Solution {
public:
int solve(vector<int>& nums,int target,int i,int sum){
    // base case
     if(i < 0) {
            if(sum == target)
                return 1;

            return 0;
        }
    int additem=solve(nums,target,i-1,sum+nums[i]);
    int subitem=solve(nums,target,i-1,sum-nums[i]);

    return additem+subitem;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,nums.size()-1,0);
    }
};