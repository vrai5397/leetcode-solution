class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        // first we have to calculate prefix sum
         int n = nums.size();

        vector<long long> prefSum(n);
        prefSum[0] = nums[0];

        for(int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i-1] + nums[i];
        }

        long long result = LLONG_MIN;

// we have to go till k-1 because after subarray start repeating
        for(int start = 0; start < k; start++) {
            long long currSum = 0;

            int i = start;

            while(i < n && i + k - 1 < n) {
                int j = i + k - 1;

                long long subSum = prefSum[j] - ((i > 0) ? prefSum[i-1] : 0);

                currSum = max(subSum, currSum + subSum);

                result = max(result, currSum);

                i += k;
            }
        }

        return result;
    }
};