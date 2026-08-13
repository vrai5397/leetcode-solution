class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // minimu len of subarray whose sum >=target
      int i=0;
      int j=0;
      int sum=0;
      int minlen=1e9;
      while(j<nums.size()){
           sum+=nums[j];
           while(sum>=target){
              minlen=min(minlen,j-i+1);
              sum-=nums[i];
              i++;
           }
           j++;
      }
      if(minlen==1e9) return 0;
return minlen;
    }
};