class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // continious window
        int i=0;
        int j=0;
       double sum=0;
       double maxaverage=-1e9;
        while(j<nums.size()){
            sum+=nums[j];
            while(j-i+1>k){
                sum-=nums[i];
                i++;
            }
            if(j-i+1==k){
            double average=sum/k;
            maxaverage=max(maxaverage,average);
            }
            j++;
        }
        return maxaverage;
    }
};