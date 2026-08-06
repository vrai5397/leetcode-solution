class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort
        if(s.size()!=t.size())
        return false;
      vector<int> freq(26,0);
      for(int i=0;i<s.size();i++){
          freq[s[i]-'a']++;
      }
      for(int i=0;i<t.size();i++){
        freq[t[i]-'a']--;
        if(freq[t[i]-'a']<0) return false;
      }
    
      return true;
    }
};