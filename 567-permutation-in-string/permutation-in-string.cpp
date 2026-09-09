class Solution {
public:
bool count(vector<int>& freq){
    for(auto x:freq){
        if(x!=0)
        return false;
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
        int k=s1.size();
        vector<int> freq(26,0);
        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
        }
        int i=0;
        int j=0;
        while(j<s2.size()){
           freq[s2[j]-'a']--;
            while(j-i+1>k){
                freq[s2[i]-'a']++;
                i++;
            }
           if(j-i+1==k&& count(freq))
           return true;
           j++;
        }
        return false;
    }
};