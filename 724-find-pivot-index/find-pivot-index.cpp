class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum=0;
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
        }
        int ps=0;
        for(int i=0;i<nums.size();i++){
            int left=ps;
            int right=totalsum-ps-nums[i];
            if(left==right) return i;
            ps+=nums[i];
        }
        return -1;
    }
};