class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //largest subarray with k zero
        int i=0;
        int j=0;
        int count=0;
        int maxsize=0;
        while(j<nums.size()){
            if(nums[j]==0)
            count++;
            while(count>k){
              if(nums[i]==0)
              count--;
              i++;
            }
            maxsize=max(maxsize,j-i+1);
            j++;
        }
        return maxsize;
    }
};