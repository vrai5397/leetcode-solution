class Solution {
public:
    int maxVowels(string s, int k) {
        // fixed size sliding window
        int i=0;
        int j=0;
      int count=0;
      int maxcount=0;
        while(j<s.size()){
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||
            s[j]=='o'||s[j]=='u')
            count++;
            while(j-i+1>k){
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||
            s[i]=='o'||s[i]=='u')
            count--;
             i++;
            }
            if(j-i+1==k)
            maxcount=max(maxcount,count);
            j++;
        }
        return maxcount;
    }
};