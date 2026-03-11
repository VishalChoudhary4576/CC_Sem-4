class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
         int n = nums.size();
        long long totalSum = 0;

        for (int x : nums)
            totalSum += x;

        if(totalSum % p == 0) return 0;

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            long long subSum = 0;

            for (int j = i; j < n; j++) {
                subSum += nums[j];

                int remaining = totalSum - subSum;

                if (remaining % p == 0 && (j - i + 1) != n) {
                    ans = min(ans, j - i + 1);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};