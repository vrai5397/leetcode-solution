class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // median of two sorted array
        int i=0;
        int j=0;
        vector<int> ans;
        while(i<nums1.size()&&j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            ans.push_back(nums1[i]);
            i++;
        }
          while(j<nums2.size()){
            ans.push_back(nums2[j]);
            j++;
        }
      double median=0;
      if(ans.size()%2==0){
         // is even
         int x1=ans.size()/2;
         median=(ans[x1]+ans[x1-1])/2.0;
      }
      else{
        // is even
         int x1=ans.size()/2;
         median=ans[x1];
      }
      return median;
    }
};