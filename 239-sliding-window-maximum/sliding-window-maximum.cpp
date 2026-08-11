class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Remove elements outside the current window
            while (!deq.empty() && deq.front() <= i - k) {
                deq.pop_front();
            }

            // Remove smaller elements
            while (!deq.empty() && nums[i] > nums[deq.back()]) {
                deq.pop_back();
            }

            // Store current index
            deq.push_back(i);

            // Window is of size k
            if (i >= k - 1) {
                ans.push_back(nums[deq.front()]);
            }
        }

        return ans;
    }
};