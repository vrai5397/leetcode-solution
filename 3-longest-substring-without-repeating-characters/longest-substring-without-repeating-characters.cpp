class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window ke bare mein 
        int i=0;
        int j=0;
        unordered_map<char,int> mp;
        int len=0;
        while(j<s.size()){
            mp[s[j]]++;
            while(mp[s[j]]>1){
                mp[s[i]]--;
                if(mp[s[i]]==0)
                mp.erase(s[i]);
                i++;
            }
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};