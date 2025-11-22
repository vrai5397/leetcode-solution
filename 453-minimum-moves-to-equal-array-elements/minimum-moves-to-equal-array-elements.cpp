class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=INT_MAX;
        for(auto x:nums){
          mini=min(x,mini);
        }
        int count=0;
        for(auto x:nums){
            count+=x-mini;
        }
        return count;
    }
};