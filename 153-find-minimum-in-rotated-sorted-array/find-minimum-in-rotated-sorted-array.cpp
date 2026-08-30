class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        int mini=INT_MAX;

        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[start]<=nums[mid]){ // left half sorted
                mini=min(mini,nums[start]);
                start=mid+1;
            }
            else{
                mini=min(mini,nums[mid]);
                end=mid-1;
            }
        }
        return mini;        
    }
};