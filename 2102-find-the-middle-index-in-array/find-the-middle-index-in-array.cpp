class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftsum(n,0);
        vector<int> rightsum(n,0);
        leftsum[0]=nums[0];
        rightsum[n-1]=nums[n-1];
        for(int i=1;i<nums.size();i++){
           leftsum[i]=nums[i]+leftsum[i-1];
        }
         for(int i=n-2;i>=0;i--){
           rightsum[i]=nums[i]+rightsum[i+1];
        }

       
        
        for(int i=0;i<nums.size();i++){
            if(leftsum[i]==rightsum[i])
            return i;
        }
        return -1;
    }
};