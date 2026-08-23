class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int>& arr) {
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;  // base case1
         if (arr[0] <= k)
            dp[0][arr[0]] = true; // base case 2

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if (arr[ind] <= target) {
                    take = dp[ind - 1][target - arr[ind]];
                }
                dp[ind][target] = take | notTake;
            }
        }
        return dp[n - 1][k];
    }

    bool canPartition(vector<int>& nums) {
        int totSum=0;
        for(int i=0;i<nums.size();i++){
            totSum+=nums[i];
        }
        if(totSum%2) return false;

        int target=totSum/2;
        return subsetSumToK(nums.size(),target,nums);
    }
};