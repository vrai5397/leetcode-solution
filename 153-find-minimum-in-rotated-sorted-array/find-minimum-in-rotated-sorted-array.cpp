class Solution {
public:
    int findMin(vector<int>& nums) {
        int num=nums[0];
        int idx=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<num){
                idx=i;
                break;
            }
        }
        if(idx==-1) return num;
        return nums[idx];
    }
};