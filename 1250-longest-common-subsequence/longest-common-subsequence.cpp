class Solution {
public:
    int solve(string& text1, string& text2,
              int i, int j,
              vector<vector<int>>& dp) {

        // Base case
        if(i < 0 || j < 0)
            return 0;

        // Already calculated
        if(dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if(text1[i] == text2[j]) {
            return dp[i][j] =
                1 + solve(text1, text2, i - 1, j - 1, dp);
        }

        // Characters don't match
        return dp[i][j] =
            max(
                solve(text1, text2, i - 1, j, dp),
                solve(text1, text2, i, j - 1, dp)
            );
    }

    int longestCommonSubsequence(string text1, string text2) {

        int i = text1.size();
        int j = text2.size();

        vector<vector<int>> dp(
            i, vector<int>(j, -1)
        );

        return solve(text1, text2, i - 1, j - 1, dp);
    }
};