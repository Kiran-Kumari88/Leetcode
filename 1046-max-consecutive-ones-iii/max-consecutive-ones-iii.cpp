class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen=0;
        int l=0,r=0;
        int zeroes=0;

        while(r<nums.size()){
            if(nums[r]==0) zeroes++;

            while(zeroes>k){
                if(nums[l]==0){
                    zeroes--;
                }
                l++;
            }
            int len=r-l+1;
            maxLen=max(len,maxLen);
            r++;
        }
        return maxLen;
        
    }
};