class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long sum = 0;
        int l = 0, ans = 1;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r]; // window increment

            long long target = nums[r];
            long long ops = (target * (r - l + 1)) - sum; // sum = purana sum // el=r-l+1 // target= target

            while (ops > k) {
                sum -= nums[l];
                l++;

                ops = target * (r - l + 1) - sum;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};