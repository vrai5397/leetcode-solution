class Solution {
public:
int solve(vector<int>& nums,int k){
    // what to do
     int i=0;
     int j=0;
    int oddcount=0;
     int count=0;
     while(j<nums.size()){
          if(nums[j]%2!=0)
          oddcount++;
          while(oddcount>k){
           if(nums[i]%2!=0)
           oddcount--;
            
               i++;
          }
          count+=j-i+1;
          j++;
     }
     return count;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        // count the number of subarray with
        //exactly k odd number
        // atmost(k)-atmost(k-1)=exactly(k)
        return solve(nums,k)-solve(nums,k-1);
    }
};