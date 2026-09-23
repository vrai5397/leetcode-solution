class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // we have to apply brain
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string key=strs[i];
            sort(key.begin(),key.end());
            mp[key].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto x:mp){
            vector<string> helper;
            for(auto y:x.second){
              helper.push_back(y);
            }
            ans.push_back(helper);
        }
        return ans;
    }
};