class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        int n = nums.size();

        for(int i = 0; i < n - 3; i++) {

            if(i > 0 && nums[i] == nums[i-1])
                continue;

            for(int j = i + 1; j < n - 2; j++) {

                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;

                long long newtarget =
                    (long long)target - nums[i] - nums[j];

                int p = j + 1;
                int q = n - 1;

                while(p < q) {

                    long long sum =
                        (long long)nums[p] + nums[q];

                    if(sum > newtarget)
                        q--;

                    else if(sum < newtarget)
                        p++;

                    else {

                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[p],
                            nums[q]
                        });

                        while(p < q && nums[p] == nums[p+1])
                            p++;

                        while(p < q && nums[q] == nums[q-1])
                            q--;

                        p++;
                        q--;
                    }
                }
            }
        }

        return ans;
    }
};