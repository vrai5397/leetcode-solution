class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        for(auto x:edges){
            for(auto y:x){
                mp[y]++;
            }
        }
        for(auto x:mp){
            if(x.second==edges.size())
            return x.first;
        }
        return -1;
    }
};