class Solution {
public:
int mod=1e9+7;
    int numSub(string s) {
        // for consecutive one contribution is (n+1)*n/2
        int i=0;
        int n=s.size();
        int count=0;
        while(i<n){
    long long j = i;
            while (j < n && s[j] == '1') j++;

            long long ones = j - i;

            // compute ones * (ones + 1) / 2 safely
            long long contrib = (ones * (ones + 1) / 2) % mod;

            count = (count + contrib) % mod;

            i = j+1;  // go to first zero
        }
        return count;
    }
};