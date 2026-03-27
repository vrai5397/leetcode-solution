class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // steps 
        // 1---> find the sorted half
        // 2---> in which half i have to serach
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target)
            return true;
    else if(nums[lo]==nums[mid]&&nums[mid]==nums[hi]){
          // trim the space 
          lo=lo+1;
          hi=hi-1;
          continue;
    }

    else if(nums[lo]<=nums[mid]){
        // left half is sorted
        if(nums[lo]<=target&&target<=nums[mid])
        hi=mid-1;

        else 
        lo=mid+1;
    }
    else{
        if(nums[mid]<=target&&target<=nums[hi])
        lo=mid+1;
        else
        hi=mid-1;
    }


        }
        return false;
    }
};