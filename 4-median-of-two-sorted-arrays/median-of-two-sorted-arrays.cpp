class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        // Binary search on smaller array
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);

        int lo = 0;
        int hi = m;

        int left = (m + n + 1) / 2;

        while (lo <= hi) {

            int mid1 = lo + (hi - lo) / 2;
            int mid2 = left - mid1;

            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            if (mid1 < m)
                r1 = nums1[mid1];

            if (mid2 < n)
                r2 = nums2[mid2];

            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];

            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];

            // Correct partition
            if (l1 <= r2 && l2 <= r1) {

                // Odd total length
                if ((m + n) % 2 != 0)
                    return max(l1, l2);

                // Even total length
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            // Partition is too far right in nums1
            else if (l1 > r2) {
                hi = mid1 - 1;
            }

            // Partition is too far left in nums1
            else {
                lo = mid1 + 1;
            }
        }

        return 0.0;
    }
};