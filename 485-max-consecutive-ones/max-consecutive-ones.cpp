class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      
        int j=0;
        int count=0;
        int maxcount=0;
        while(j<nums.size()){
           if(nums[j]==1){
           count++;
              maxcount=max(maxcount,count);
             j++;
           }
           while(j<nums.size()&&nums[j]==0){
             j++;
             count=0;
           }
           
           
        
        }
        return maxcount;
    }
};