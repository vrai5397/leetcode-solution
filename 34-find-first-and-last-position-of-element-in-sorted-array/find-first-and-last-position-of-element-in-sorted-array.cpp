class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        // finding the lower bound
        int lo=0;
        int hi=arr.size()-1;
        int ans1=-1;
  while(lo<=hi){
    int mid=lo+(hi-lo)/2;
     if(arr[mid]==target){
         ans1=mid;
         hi=mid-1;
     }
   else if(arr[mid]>target)
     hi=mid-1;
     else
     lo=mid+1;
  }

        lo=0;
        hi=arr.size()-1;
        int ans2=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==target){
                ans2=mid;
                lo=mid+1;
            }
          else if(arr[mid]>target)
          hi=mid-1;
          else
          lo=mid+1;
        }
       return{ans1,ans2};
    }
};