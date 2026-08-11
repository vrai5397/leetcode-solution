class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        // n-k
        // 22
        // tell the window of n-k size with minimum sum
        int totalsum=0;
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
        } 

        int i=0;
        int j=0;
        int sum=0;
        int minsum=1e9;
        while(j<nums.size()){
            sum+=nums[j];
            while(j-i+1>n-k){
               sum-=nums[i];
               i++;
            }
            if(j-i+1==n-k)
            minsum=min(minsum,sum);
            j++;
        }  

        return totalsum-minsum;
    }
};