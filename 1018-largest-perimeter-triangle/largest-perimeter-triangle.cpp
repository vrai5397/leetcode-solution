class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // 1 2 2
       
        sort(nums.begin(),nums.end());
        int maxperi=0;
        for(int i=nums.size()-3;i>=0;i--){
            int a=nums[i];
            int b=nums[i+1];
            int c=nums[i+2];
            if(a+b>c)
            maxperi=max(maxperi,a+b+c);
        }
        return maxperi;
    }
};