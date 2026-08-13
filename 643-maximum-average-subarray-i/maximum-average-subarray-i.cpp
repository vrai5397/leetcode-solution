class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        double sum=0;
        double maxavg=-1e9;
        while(j<nums.size()){
             sum+=nums[j];
             if(j-i+1>k){
                sum-=nums[i];
                i++;
             }
             if(j-i+1==k)
       maxavg=max(maxavg,sum/k);
j++;
        }
        return maxavg;
    }
};