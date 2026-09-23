class Solution {
public:
    int findMin(vector<int>& nums) {
         int lo=0;
         int hi=nums.size()-1;
         int mini=INT_MAX;
         while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[lo]<=nums[mid]){
                // first half is sorted
                mini=min(nums[lo],mini);
                lo=mid+1;
            }
            else{
                 mini=min(nums[mid],mini);
                 hi=mid-1;
            }
         }
         return mini;
    }
};