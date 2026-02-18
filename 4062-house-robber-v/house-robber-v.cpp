class Solution {
public:

    vector<long long> dp;

    long long solve(vector<int>& nums, vector<int>& colors, int i){

        // base case
        if(i >= nums.size())
            return 0;

        // if already computed
        if(dp[i] != -1)
            return dp[i];

        long long include = 0;

        // pick case
        if(i + 1 < nums.size() && colors[i] == colors[i+1])
            include = nums[i] + solve(nums, colors, i + 2);
        else
            include = nums[i] + solve(nums, colors, i + 1);

        // not pick case
        long long exclude = solve(nums, colors, i + 1);

        // store and return
        return dp[i] = max(include, exclude);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {

        int n = nums.size();
        dp.assign(n, -1);

        return solve(nums, colors, 0);
    }
};
