class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        unordered_set<int> st;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>(n/3)){
               st.insert(nums[i]);
            }
        }
        for(auto x:st)
        ans.push_back(x);

        return ans;

    }
};