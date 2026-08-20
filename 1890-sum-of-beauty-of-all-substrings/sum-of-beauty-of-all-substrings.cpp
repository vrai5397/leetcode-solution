class Solution {
public:
    int beautySum(string s) {
        // approach
        int ans=0;
        for(int i=0;i<s.size();i++){
            vector<int> freq(26,0);
           
            for(int j=i;j<s.size();j++){
                 int maxifreq=0;
                 int minifreq=1e9;
               freq[s[j]-'a']++;
               for(int k=0;k<26;k++){
                  if(freq[k]>0){
                    maxifreq=max(maxifreq,freq[k]);
                    minifreq=min(minifreq,freq[k]);
                  }
               }
               ans+=maxifreq-minifreq;
            }
        }
        return ans;
    }
};