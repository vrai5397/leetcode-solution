class Solution {
public:
bool checkzero(vector<int> freq){
    for(int i=0;i<26;i++){
        if(freq[i]!=0) return false;
       
    }
    return true;
}
    bool checkInclusion(string s1, string s2) {
        //suppose we have window of s1 size
        // find the window of that size in s2 with same alphabet
         vector<int> freq(26,0);
         int k=s1.size();
         for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
         }
         // sliding window
         int i=0;
         int j=0;
         while(j<s2.size()){
             freq[s2[j]-'a']--;
             while(j-i+1>k){
                freq[s2[i]-'a']++;
                i++;
             }

             if(j-i+1==k&& checkzero(freq))
             return true;

             j++;
         }
         return false;
    }
};