class Solution {
public:
// code to find subarray with <=goal
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
        // simple formaula
        // atmost(goal)-atmost(goal-1)=exact(goal)
         return solve(nums,goal)-solve(nums,goal-1);
    }
};