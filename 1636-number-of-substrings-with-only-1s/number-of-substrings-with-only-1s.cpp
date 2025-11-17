class Solution {
public:
    int mod = 1e9 + 7;

    int numSub(string s) {
        long long count = 0;   // must be long long
        int n = s.size();

        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                i++;
                continue;
            }

            long long j = i;
            while (j < n && s[j] == '1') j++;

            long long ones = j - i;

            // compute ones * (ones + 1) / 2 safely
            long long contrib = (ones * (ones + 1) / 2) % mod;

            count = (count + contrib) % mod;

            i = j;  // go to first zero
        }

        return (int)count;
    }
};
