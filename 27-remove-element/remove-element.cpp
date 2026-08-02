class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
           vector<int> ans;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
            ans.push_back(nums[i]);
          
        }
          else count++;
        }
        for(int i=0;i<count;i++)
        ans.push_back(val);

        
        nums=ans;

        return nums.size()-count;
    }
};