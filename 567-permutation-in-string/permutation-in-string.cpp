class Solution {
public:
bool freqcount(vector<int>& freq){
    for(int i=0;i<26;i++){
    if(freq[i]!=0) return false;
    }
return true;

}
    bool checkInclusion(string s1, string s2) {
        //we have to find string of ab length in s2
        // continious manner
        // substring s1 size
       // sliding window
       int i=0;
       int j=0;
       vector<int> freq(26,0);
       for(int i=0;i<s1.size();i++)
       freq[s1[i]-'a']++;
    int k=s1.size();
       while(j<s2.size()){
          freq[s2[j]-'a']--;
           while(j-i+1>k){
              freq[s2[i]-'a']++;
              i++;
           }
           if(j-i+1==k&& freqcount(freq))
           return true;
           j++;
       }
       return false;
    }
};