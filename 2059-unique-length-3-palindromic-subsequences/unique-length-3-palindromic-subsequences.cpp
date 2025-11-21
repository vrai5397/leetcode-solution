class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters(s.begin(), s.end());
        int result = 0;

        for (char letter : letters) {

            int left = -1, right = -1;

            // find leftmost and rightmost occurrences
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == letter) {
                    if (left == -1)
                        left = i;
                    right = i;
                }
            }

            // if less than 2 occurrences → skip
            if (left == -1 || right - left < 2) continue;

            // now count distinct middle characters
            unordered_set<char> st;
            for (int j = left + 1; j < right; j++)
                st.insert(s[j]);

            result += st.size();
        }

        return result;
    }
};
