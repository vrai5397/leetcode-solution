class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> pos;
        queue<int> neg;
       
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
            pos.push(nums[i]);
            else
            neg.push(nums[i]);
        }
        int i=0;
        while(!pos.empty()){
             nums[i]=pos.front();
             pos.pop();
             i++;
               nums[i]=neg.front();
             neg.pop();
             i++;
        }
        return nums;
    }
};