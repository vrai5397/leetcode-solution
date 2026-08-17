class Solution {
public:
int solve(vector<int>& nums,int goal){
    if(goal<0) return 0;
    int i=0;
    int j=0;
    int sum=0;
    int count=0;
    while(j<nums.size()){
        sum+=nums[j];
         while(sum>goal){
           sum-=nums[i];
           i++;
         }
         count+=j-i+1;
         j++;
    }
    return count;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // sliding window concept
        // atmost(k)-atmost(k-1)
        return solve(nums,goal)-solve(nums,goal-1);
    }
};