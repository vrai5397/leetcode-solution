class Solution {
public:
  int lowerBound(vector<int>& arr, int target) {
        // code here
        int lo=0;
        int hi=arr.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]>=target){
                hi=mid-1;
            }
            else 
            lo=mid+1;
        }
        return lo;
    }
     int nextBound(vector<int>& arr, int target) {
        // code here
        int lo=0;
        int hi=arr.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
           if(arr[mid]<=target)
           lo=mid+1;
           else
           hi=mid-1;
        }
        return hi;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
        return {-1,-1};
        int index1=lowerBound(nums,target);
          if(index1>=nums.size()||nums[index1]!=target)
        return {-1,-1};
        int index2=nextBound(nums,target);
      
        return {index1,index2};
    }
};