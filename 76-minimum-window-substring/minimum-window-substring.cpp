class Solution {
public:
bool solve(unordered_map<char,int>& mp){
    for(auto x:mp){
        if(x.second>0)
        return false;
    }
    return true;
}
    string minWindow(string s, string t) {
        if(s.size()<t.size())
        return "";
       int i=0;
       int j=0;
       int minlen=INT_MAX;
       int start=0;
       unordered_map<char,int> mp;
       for(auto x:t){
          mp[x]++;
       }
       while(j<s.size()){
           mp[s[j]]--;
           while(solve(mp)){
              if(j-i+1<minlen){
                 minlen=j-i+1;
                 start=i;
              }
              mp[s[i]]++;
              if(mp[s[i]]==0)
              mp.erase(s[i]);
              i++;
           }
           j++;
       }
       if(minlen==INT_MAX)
       return "";
       return s.substr(start,minlen);
    }
};