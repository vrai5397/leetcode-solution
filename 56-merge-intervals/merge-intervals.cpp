class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(auto interval:intervals){
            if(ans.empty())
            ans.push_back({interval[0],interval[1]});
         else  if(ans.back()[1]>=interval[0]){
            // overlapping interval
             int maxi=max(interval[1],ans.back()[1]);
             ans.back()[1]=maxi;
           }
           else{
             ans.push_back({interval[0],interval[1]});
           }
        }
        return ans;
    }
};