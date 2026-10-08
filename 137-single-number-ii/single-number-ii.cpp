class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mpp;

        for(int it:nums){
            mpp[it]++;
        }

        for(int it:nums){
            if(mpp[it]==1){
                return it;
            }
        }
        return -1;
        
    }
};