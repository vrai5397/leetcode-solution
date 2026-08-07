class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // come on brute force
        // pick the first letter
        string ans="";
        for(int i=0;i<strs[0].size();i++){
      // comapare from all other string
           for(int j=1;j<strs.size();j++){
              if(strs[0][i]!=strs[j][i])
                return ans;
               
           }
           ans+=strs[0][i];
        }
        return ans;
    }
};