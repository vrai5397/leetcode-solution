class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // use of hashmap+sliding window
        int i=0;
        int j=0;
        unordered_map<char,int> mp;
        int maxlen=0;
        while(j<s.size()){
          mp[s[j]]++;
          while(mp[s[j]]>1){
             mp[s[i]]--;
             if(mp[s[i]]==0)
             mp.erase(s[i]);
             i++;
          }
          maxlen=max(maxlen,j-i+1);
          j++;
        }
return maxlen;
    }
};