class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            if(abs(nums[i])>nums[j]){
                swap(nums[i],nums[j]);
                j--;
            }
            else i++;
        }
         vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]*nums[i]);
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};