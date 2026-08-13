class Solution {
public:
int freqcount(unordered_map<char,int>& mp){
    for(auto x:mp){
        if(x.second>0)
        return false;
    }
    return true;
}
    string minWindow(string s, string t) {
       unordered_map<char,int> mp;
       for(int i=0;i<t.size();i++)
       mp[t[i]]++;
       int i=0;
       int j=0;
       int minlen=1e9;
       int start=0;
       while(j<s.size()){
          mp[s[j]]--;
          while(freqcount(mp)){
             if(j-i+1<minlen){
                start=i;
                minlen=j-i+1;
             }
             mp[s[i]]++;
            //  if(mp[s[i]]==0)
            //  mp.erase(s[i]);
             i++;
          }
j++;
       }
if(minlen==1e9)
return "";
return s.substr(start,minlen);
    }
};