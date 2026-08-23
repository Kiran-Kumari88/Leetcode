class Solution {
public:
    int func(int i,int n,vector<int>&dp){
        if(i==0) return 1;
        if(i==1) return 1;
        if(dp[i]!=-1){
            return dp[i];
        }

        int left=func(i-1,n,dp);
        int right=func(i-2,n,dp);

        return dp[i]=left+right;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return func(n,n,dp);
    }
};