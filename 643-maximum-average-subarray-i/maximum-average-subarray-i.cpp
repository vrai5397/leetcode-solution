class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        double average=INT_MIN;
        double sum=0;
        while(j<nums.size()){
            sum+=nums[j];
            while(j-i+1>k){
                sum-=nums[i];
                i++;
            }
            if(j-i+1==k)
           average=max(average,sum/(double)k);
           j++;
        }
        return average;
    }
};