class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ones=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1)
            ones++;
        }
        if(ones>0)
        return n-ones;
        int minsteps=INT_MAX;
        for(int i=0;i<n-1;i++){
              int gcds=nums[i];
              for(int j=i+1;j<n;j++){
                gcds=gcd(gcds,nums[j]);
                if(gcds==1){
                minsteps=min(minsteps,j-i);
                  break;
                }
              }
        }
        if(minsteps==INT_MAX) return -1;
        return minsteps+(n-1);
    }
};