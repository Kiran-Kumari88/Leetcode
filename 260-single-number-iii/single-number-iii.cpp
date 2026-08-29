class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr=0;
        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            xorr=xorr^nums[i];
        }
        int rightMost= (xorr & (xorr-1)) ^ xorr;

        int b1=0;
        int b2=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] & rightMost){
                b1=b1^nums[i];
            }
            else{
                b2=b2^nums[i];
            }
        }
        ans.push_back(b1);
        ans.push_back(b2);

        return ans;
    }
};