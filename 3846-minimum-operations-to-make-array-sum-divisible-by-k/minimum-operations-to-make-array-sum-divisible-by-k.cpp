class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int r=sum/k;
        if(sum%k==0)
        return 0;
        else if(r==0)
        return sum;
        else
        return sum-r*k;
    }
};