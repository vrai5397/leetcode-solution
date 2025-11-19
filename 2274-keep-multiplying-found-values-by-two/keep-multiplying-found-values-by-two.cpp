class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>st(nums.begin(),nums.end());
        while(1){
            if(st.count(original)>0)
            original*=2;
            else
            break;
        }
        return original;
    }
};