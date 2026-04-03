class Solution {
public:
    int search(vector<int>& nums, int target) {
        // roted array will alwyas have one side sorted
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>=nums[lo]){
                // left half is sorted
                if(nums[lo]<=target&&target<nums[mid])
                hi=mid-1;
                else
                lo=mid+1;
            }
            else{
                // right half is sorted
                 if(nums[mid]<target&&target<=nums[hi])
                lo=mid+1;
                else
                hi=mid-1;
            }
        }

        return -1;
    }
};