class Solution {
public:
bool solve(vector<int>& freq){
    for(auto x:freq){
        if(x!=0)
        return false;
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
        // we have to find s1 size window
        if(s2.size()<s1.size())
        return false;
        int k=s1.size();
        int i=0;
        int j=0;
        vector<int> freq(26,0);
        for(auto x:s1)
        freq[x-'a']++;
        while(j<s2.size()){
            freq[s2[j]-'a']--;
            while(j-i+1>k){
               freq[s2[i]-'a']++;
               i++;
            }
            if(j-i+1==k&& solve(freq))
            return true;
            j++;
        }
        return false;
    }
};