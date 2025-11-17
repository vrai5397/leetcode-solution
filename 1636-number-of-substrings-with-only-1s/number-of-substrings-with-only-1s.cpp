class Solution {
public:
int mod=1e9+7;
    int numSub(string s) {
        int n=s.size();
        long long count=0;
        for(int i=0;i<n;i++){
           if(s[i]=='0') continue;
            long long j=i;
            while(j<n&& s[j]!='0')
            j++;
        long long ones=j-i;
        long long contri=(ones*(ones+1))/2;
        count=(count+contri)%mod;
         i=j;

        }
        return (int) count;
    }
};