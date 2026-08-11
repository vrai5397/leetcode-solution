class Solution {
public:

    string minWindow(string s, string t) {
        // general approach
        
        int start=0;
        unordered_map<char,int> mp;
        for(int i=0;i<t.size();i++){
           mp[t[i]]++;
        }
        int i=0;
        int j=0;
        int minlen=1e9;
        int count=0;
        while(j<s.size()){
            if(mp[s[j]]>0)
            count++;
            mp[s[j]]--;
            while(count==t.size()){
              if(j-i+1 < minlen) {
    minlen = j-i+1;
    start = i;
}
               mp[s[i]]++;
               if(mp[s[i]]>0)
               count--;
               i++;
            }
            j++;
        }
        
        if(minlen == 1e9)
    return "";
        return s.substr(start,minlen);
    }
};
