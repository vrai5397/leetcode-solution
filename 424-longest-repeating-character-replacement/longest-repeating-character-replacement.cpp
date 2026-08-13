class Solution {
public:
    int characterReplacement(string s, int k) {
        // j-i+1-max
        int i=0;
        int j=0;
        unordered_map<char,int> mp;
        int maxfreq=0;
        int maxlen=0;
        while(j<s.size()){
             mp[s[j]]++;
           for(auto x:mp)
           maxfreq=max(maxfreq,x.second);
           // remaining chracter
           while((j-i+1)-maxfreq>k){
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