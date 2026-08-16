class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> pos;
        queue<int> neg;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
            pos.push(nums[i]);
            else
            neg.push(nums[i]);
        }
        while(!pos.empty()){
             ans.push_back(pos.front());
             pos.pop();
               ans.push_back(neg.front());
             neg.pop();
        }
        return ans;
    }
};